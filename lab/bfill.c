#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
void boundaryFill(int x, int y, int fcolor, int bcolor){
	if(getpixel(x,y) != fcolor && getpixel(x,y) != bcolor){
		delay(3);
		putpixel(x,y,fcolor);
		boundaryFill(x+1, y, fcolor, bcolor);
		boundaryFill(x-1, y, fcolor, bcolor);
		boundaryFill(x, y+1, fcolor, bcolor);
		boundaryFill(x, y-1, fcolor, bcolor);
	}
}

void main(){
	int gd = DETECT, gm, x, y;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	
	printf("Enter the seed points: ");
	scanf("%d %d", &x, &y);
	
	setcolor(RED);
	rectangle(50, 50, 100, 100);
	boundaryFill(x, y, CYAN, RED);
	getch();
	closegraph();
}
