#include <stdio.h>
#include<stdlib.h>

#define WIDTH 80
#define HEIGHT 24
#define EMPTY '_'
#define PIXEL '*'


char picture[HEIGHT][WIDTH];
void clearPicture()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            picture[y][x] = EMPTY;
        }
    }
}

/* Display the canvas */
void displayPicture()
{
 for (int y = 0; y < HEIGHT; y++)
 {
      for (int x = 0; x < WIDTH; x++)
    {
          printf("%c", picture[y][x]);
    }
        printf("\n");
    }
}
void setPixel(int x, int y)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        picture[y][x] = PIXEL;
    }
}
void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = dx + dy;

    while (1)
    {
        setPixel(x1, y1);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 >= dy)
        {
            err += dy;
            x1 += sx;
        }

        if (e2 <= dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void drawRectangle(int x1,int y1,int x2,int y2)
{
    for (int x = x1; x <= x2; x++)
    {
        setPixel(x, y1);
        setPixel(x, y2);
    }

    for (int y = y1; y <= y2; y++)
    {
        setPixel(x1, y);
        setPixel(x2, y);
    }
}
void drawCircle(int cx, int cy, int r)
{
    int x = r;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        setPixel(cx + x, cy + y);
        setPixel(cx + y, cy + x);
        setPixel(cx - y, cy + x);
        setPixel(cx - x, cy + y);
        setPixel(cx - x, cy - y);
        setPixel(cx - y, cy - x);
        setPixel(cx + y, cy - x);
        setPixel(cx + x, cy - y);

        y++;

        if (err <= 0)
            err += 2 * y + 1;
        else
        {
            x--;
            err -= 2 * x + 1;
        }
    }
}
void drawTriangle(int x1, int y1,
                  int x2, int y2,
                  int x3, int y3)
{
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}
int main()
{
   int choice;

    clearPicture();

    while (1)
    {
    printf("\n===== ASCII Drawing Program =====\n");
    printf("1. Draw Line\n");
     printf("2. Draw Rectangle\n");
     printf("3. Draw Circle\n");
     printf("4. Draw Triangle\n");
     printf("5. Display Canvas\n");
     printf("6. Clear Canvas\n");
     printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            drawLine(5, 5, 25, 15);
            printf("Line drawn.\n");
            break;

        case 2:
            drawRectangle(35, 5, 55, 15);
            printf("Rectangle drawn.\n");
            break;

        case 3:
            drawCircle(20, 10, 5);
            printf("Circle drawn.\n");
            break;

        case 4:
            drawTriangle(60, 5, 70, 15, 50, 15);
            printf("Triangle drawn.\n");
            break;

        case 5:
            displayPicture();
            break;

        case 6:
            clearPicture();
            printf("Canvas cleared.\n");
            break;

        case 0:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0; 
  
}
