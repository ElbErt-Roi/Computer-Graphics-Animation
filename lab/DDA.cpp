#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main(){
	int gd = DETECT, gm;
	float x1,y1,x2,y2,dx,dy,steps;
	float xinc,yinc , x,y;
	int i;
	initgraph(&gd ,&gm , "C:\\TURBOC3\\BGI");
	
	printf("Enter Starting Coodinates (x1 y1): ");
	scanf("%f %f",&x1 ,&y1);
	printf("Enter Ending Coodinates (x2 y2): ");
	scanf("%f %f",&x2,&y2);
	dx = x2-x1;
	dy = y2-y1;
	
	if(abs(dx)> abs(dy))
	steps= abs(dx);
	else
	steps = abs(dy);
	xinc = dx / steps;
	yinc = dy / steps;
	x = x1;
	y = y1;
	for (i = 0;i<= steps;i++){
		putpixel(floor(x),floor(y),WHITE);
		x +=xinc;
		y+=yinc;
		
	}
	getch();
	closegraph();
	
}
