#include <stdio.h>

void draw_box(int length, int width);

int main(void)
{
  int length, width;

  printf("Enter the length/height/rows of the box: ");
  scanf("%u", &length);
  printf("Enter the width/columns of the box: ");
  scanf("%u", &width);

  draw_box(length, width);

  return 0;
}

void draw_box(int length, int width)
{
  int i, j;
  for(i = 0; i < length; i++)
  {
    for(j = 0; j < width; j++)
      printf("# ");
    printf("\n");
  }

  return;
}
