Translation:
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
void translate(int, int, int, int, int, int);
void drawtriangle(int, int, int, int, int, int);
void main()
{
	int gd=DETECT, gm;
	int x1, y1, x2,y2, x3,y3;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter the first point of the triangle: ");
	scanf("%d" "%d", &x1, &y1);
	printf("Enter the second point of the triangle: ");
	scanf("%d" "%d", &x2, &y2);
	printf("Enter the third point of the triangle: ");
	scanf("%d" "%d", &x3, &y3);
	drawtriangle(x1, y1, x2, y2, x3, y3);
	translate(x1, y1, x2, y2, x3, y3);
	getch();
}
void translate(int x1, int y1, int x2, int y2, int x3, int y3) 
{
	int tx, ty;
	printf("Enter the translation factors: ");
	scanf("%d %d", &tx, &ty);
	x1 +=tx;
	y1 += ty;
	x2 +=tx;
	y2 += ty;
	x3 +=tx;
	y3 += ty;
	setcolor(RED);
	drawtriangle(x1, y1, x2, y2, x3, y3);
}
void drawtriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
}

Scaling:
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
void scaling(int, int, int, int, int, int);
void drawtriangle(int, int, int, int, int, int);
void main()
{
	int gd=DETECT, gm;
	int x1, y1, x2,y2, x3,y3;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter the first point of the triangle: ");
	scanf("%d" "%d", &x1, &y1);
	printf("Enter the second point of the triangle: ");
	scanf("%d" "%d", &x2, &y2);
	printf("Enter the third point of the triangle: ");
	scanf("%d" "%d", &x3, &y3);
	drawtriangle(x1, y1, x2, y2, x3, y3);
	scaling(x1, y1, x2, y2, x3, y3);
	getch();
}
void scaling(int x1, int y1, int x2, int y2, int x3, int y3) 
{
	int sx, sy;
	printf("Enter the scaling factors: ");
	scanf("%d %d", &sx, &sy);
	x1 *=sx;
	y1 *= sy;
	x2 *=sx;
	y2 *= sy;
	x3 *=sx;
	y3 *= sy;
	setcolor(RED);
	drawtriangle(x1, y1, x2, y2, x3, y3);
}
void drawtriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
}

Rotation:
#include<stdio.h>
#include<graphics.h>
#include<math.h>
void rotate(int, int, int, int, float);
void drawtriangle(int, int, int, int, int, int);
void rotatetriangle(int, int, int, int, int, int, float);
void main()
{
	int gd=DETECT, gm;
	int x1, y1, x2, y2, x3, y3, deg;
	float rad;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter the first point of the line: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter the second point of the line: ");
	scanf("%d %d", &x2, &y2);
	printf("Enter the third point of the line: ");
	scanf("%d %d", &x3, &y3);
	drawtriangle(x1, y1, x2, y2, x3, y3);
	printf("Enter the rotation angle: ");
	scanf("%d", &deg);
	rad = deg*3.14/180;
	rotatetriangle(x1, y1, x2, y2, x3, y3, rad);
	getch();
}

void drawtriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x1, y1, x3, y3);
}

void rotate(int x1, int y1, int x2, int y2, float rad)
{
	int x0, y0, x, y;
	x0 = x1*cos(rad) - y1*sin(rad);
	y0 = x1*sin(rad) + y1*cos(rad);
	x = x2*cos(rad) - y2*sin(rad);
	y = x2*sin(rad) + y2*cos(rad);
	line(x0, y0, x, y);
}

void rotatetriangle(int x1, int y1, int x2, int y2, int x3, int y3, float rad)
{
	rotate(x1, y1, x2, y2, rad);
	rotate(x2, y2, x3, y3, rad);
	rotate(x3, y3, x1, y1, rad);
}

Reflection:
#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main()
{
	int gd=DETECT, gm;
	int x1=100, y1=100;
	int x2=100, y2=200, x3=200, y3=100;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	line(getmaxx()/2, 0, getmaxx()/2, getmaxy());
	line(0, getmaxy()/2, getmaxx(), getmaxy()/2);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
	getch();
	
	//Reflection about the origin
	setcolor(1);
	line(getmaxx()-x1, getmaxy()-y1, getmaxx()-x2, getmaxy()-y2);
	line(getmaxx()-x2, getmaxy()-y2, getmaxx()-x3, getmaxy()-y3);
	line(getmaxx()-x3, getmaxy()-y3, getmaxx()-x1, getmaxy()-y1);
	getch();
	
	//Reflection along y-axis
	setcolor(2);
	line(getmaxx()-x1, y1, getmaxx()-x2, y2);
	line(getmaxx()-x2, y2, getmaxx()-x3, y3);
	line(getmaxx()-x3, y3, getmaxx()-x1, y1);
	getch();
	
	//Reflection along x-axis
	setcolor(3);
	line(x1, getmaxy()-y1, x2, getmaxy()-y2);
	line(x2, getmaxy()-y2, x3, getmaxy()-y3);
	line(x3, getmaxy()-y3, x1, getmaxy()-y1);
	getch();
	closegraph();
}

Character Draw:
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void drawHouse()
{
	rectangle(200, 200, 300, 300);
	line(200, 200, 250, 150);
	line(250, 150, 300, 200);
	rectangle(230, 250, 270, 300);
}

void drawCharacter(int x, int y)
{
	setcolor(WHITE);
	circle(x, y, 10);
	line(x, y+10, x, y+30);
	line(x, y+30, x-10, y+40);
	line(x, y+30, x+10, y+40);
	line(x, y+15, x-10, y+20);
	line(x, y+15, x+10, y+20);
}

void clearCharacter(int x, int y)
{
	setcolor(BLACK);
	circle(x, y, 10);
	line(x, y+10, x, y+30);
	line(x, y+30, x-10, y+40);
	line(x, y+30, x+10, y+40);
	line(x, y+15, x-10, y+20);
	line(x, y+15, x+10, y+20);
}

void drawWin(int winx, int winy)
{
	setcolor(GREEN);
    circle(winx, winy, 40);
}
void main()
{
	int gd=DETECT, gm;
	int x=100, y=250;
	int winx, winy;
	char key;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	drawHouse();
	 winx = getmaxx() - 40;
    winy = getmaxy() - 40;
	drawWin(winx, winy);
	drawCharacter(x, y);
	while(1)
	{
		if(kbhit())
		{
			key = getch();
			clearCharacter(x, y);
			if(key == 72)
				y -= 10; 	//UP arrow key
			if(key == 80)
				y += 10; 	//DOWN arrow key
			if(key == 75)
				x -= 10; 	//LEFT arrow key
			if(key == 77)
				x += 10; 	//RIGHT arrow key
			drawCharacter(x, y);
			if(x>200 && x<300 && y>200 && y<300)
			{
				setcolor(RED);
				outtextxy(200, 250, "GAME OVER!!!");
				break;
			}
			if((x > winx-40 && x < winx+40) &&
               (y > winy-40 && y < winy+40))
            {
                setcolor(YELLOW);
                outtextxy(250, 100, "YOU WIN!!!");
                break;
            }
			
		}
	}
	getch();
	delay(500);
}

3D Translation:
#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main()
{
	int gd=DETECT, gm;
	int tx=100, ty=120;
	int left=50, top=200, right=150, bottom=300, depth=50;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	bar3d(left, top, right, bottom, depth, 1);
	getch();
	bar3d(left+tx, top+ty, right+tx, bottom+ty, depth, 1);
	getch();
	closegraph();
}

3D Scaling:
#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main()
{
	int gd=DETECT, gm;
	int left=50, top=200, right=150, bottom=300, depth=50;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	bar3d(left, top, right, bottom, depth, 1);
	getch();
	bar3d(left*2, top*2, right*2, bottom*2, depth*2, 1);
	getch();
	closegraph();
}
