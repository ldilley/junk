#include <stdio.h>

int main(void)
{
  int arr[10];

  printf("Address using \"arr\": %ld\n", arr);
  printf("Address using \"&arr\": %ld\n", &arr);
  printf("Address using \"&arr[0]\": %ld\n", &arr[0]);

  return 0;
}
