#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
void floodFill(int x, int y, int newcolor, int oldcolor){
	if(getpixel(x,y) == oldcolor){
		delay(3);
		putpixel(x,y,newcolor);
		floodFill(x+1, y, newcolor, oldcolor);
		floodFill(x-1, y, newcolor, oldcolor);
		floodFill(x, y+1, newcolor, oldcolor);
		floodFill(x, y-1, newcolor, oldcolor);
	}
}

void main(){
	int gd = DETECT, gm, x, y;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter the seed points: ");
	scanf("%d %d",&x, &y);

	setcolor(RED);
	rectangle(50, 50, 100, 100);
	floodFill(x, y, WHITE, BLACK);
	getch();
	closegraph();
}
