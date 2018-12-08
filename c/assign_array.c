#include <stdio.h>

int main(void)
{
  int arr[10];
  int *p_arr = &arr[2];

  *p_arr = 100;
  printf("%d\n", arr[2]);

  return 0;
}
