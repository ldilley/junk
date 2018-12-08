#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 10
#define Y 10
#define Z 10

void fill_array(int arr[][Y][Z]);
void print_array(int arr[][Y][Z]);

int main(void)
{
  int arr[X][Y][Z];
  srand(time(NULL));

  fill_array(arr);
  print_array(arr);
}

void fill_array(int arr[][Y][Z])
{
  int i, j, k;

  for(i = 0; i < X; i++)
    for(j = 0; j < Y; j++)
      for(k = 0; k < Z; k++)
        arr[i][j][k]=rand();

  return;
}

void print_array(int arr[][Y][Z])
{
  int i, j, k;

  for(i = 0; i < X; i++)
  {
    for(j = 0; j < Y; j++)
    {
      for(k = 0; k < Z; k++)
      {
        printf("array[%d][%d][%d] = %d\n", i, j, k, arr[i][j][k]);
      }
      printf("Press any key to continue.\n");
      getchar();
    }
  }

  return;
}
