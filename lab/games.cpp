#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void drawHouse()
{
    // House body
    rectangle(200, 200, 300, 300);
    // Roof
    line(200, 200, 250, 150);
    line(250, 150, 300, 200);
    // Door
    rectangle(230, 250, 270, 300);
    // Door handle
    circle(260, 275, 3);
    // Window
    rectangle(210, 220, 230, 240);
    line(220, 220, 220, 240);
    line(210, 230, 230, 230);
}

void drawObstacle(int x1, int y1, int x2, int y2)
{
    setcolor(RED);
    rectangle(x1, y1, x2, y2);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x1+1, y1+1, RED);
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

int hitObstacle(int x, int y, int x1, int y1, int x2, int y2)
{
    if(x > x1 && x < x2 && y > y1 && y < y2)
        return 1;
    return 0;
}

void main()
{
    int gd = DETECT, gm;
    int x = 100, y = 250;
    char key;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    // Draw house
    drawHouse();
    
    // Draw obstacles (3 additional obstacles)
    drawObstacle(100, 100, 180, 130);      // Obstacle 1
    drawObstacle(350, 150, 430, 180);      // Obstacle 2
    drawObstacle(300, 350, 450, 380);      // Obstacle 3
    drawObstacle(50, 400, 120, 450);       // Obstacle 4 (new)
    drawObstacle(400, 50, 480, 100);       // Obstacle 5 (new)
    
    // Draw door area indicator (green rectangle showing door area)
    setcolor(GREEN);
    rectangle(230, 250, 270, 300);
    outtextxy(235, 255, "DOOR");
    
    drawCharacter(x, y);

    while(1)
    {
        if(kbhit())
        {
            key = getch();

            clearCharacter(x, y);

            if(key == 72)  // Up arrow
                y -= 10;

            if(key == 80)  // Down arrow
                y += 10;

            if(key == 75)  // Left arrow
                x -= 10;

            if(key == 77)  // Right arrow
                x += 10;
                
            // Boundary checking (optional - prevents character from going out of screen)
            if(x < 20) x = 20;
            if(x > getmaxx() - 20) x = getmaxx() - 20;
            if(y < 20) y = 20;
            if(y > getmaxy() - 20) y = getmaxy() - 20;

            drawCharacter(x, y);

            // Check if character enters the house door (win condition)
            if(x > 230 && x < 270 && y > 250 && y < 300)
            {
                setcolor(YELLOW);
                settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
                outtextxy(250, 100, "YOU WIN!!!");
                break;
            }
            
            // Check obstacle collisions (lose condition)
            if(
                hitObstacle(x, y, 100, 100, 180, 130) ||
                hitObstacle(x, y, 350, 150, 430, 180) ||
                hitObstacle(x, y, 300, 350, 450, 380) ||
                hitObstacle(x, y, 50, 400, 120, 450) ||
                hitObstacle(x, y, 400, 50, 480, 100)
              )
            {
                setcolor(RED);
                settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
                outtextxy(200, 240, "GAME OVER!!!");
                break;
            }
        }
          // Small delay to control game speed
    }
    getch();
    closegraph();
}
