#include <stdio.h>

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

int main()
{
     printf("Canvas created successfully!\n");
     printf("Canvas size: %d x %d\n", WIDTH, HEIGHT);
     return 0;
}
