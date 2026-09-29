#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void main(){
	int gd = DETECT ,gm ,error,x1,y1,x2,y2;
	int dx, dy,p,x,y;
	initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");
	
	printf("Enter Co-ordinates of first points: ");
	scanf("%d %d ", &x1,&y1);
	printf("Eneter Co-orinates of second points: ");
	scanf("%d %d",&x2,&y2);
	
	dx= x2 -x1;
	dy= y2 -y1;
	x = x1;
	y = y1;
	p=2*dy-dx;
	while (x < x2){
		putpixel(x,y,7);
		x++;
		if(p<0) 
		p=p+2*dy;
		else{
			y=y+1;
			p=p+2*dy-2*dx;
		}
	}
	getch();
	closegraph();
}
