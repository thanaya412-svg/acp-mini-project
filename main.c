#include <stdio.h>
#include<stdlib.h>

#define WIDTH 80
#define HEIGHT 24
#define EMPTY '_'

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
int main()
{
    
     printf("Canvas created successfully!\n");
     printf("Canvas size: %d x %d\n", WIDTH, HEIGHT);
     return 0;
}
