#include <stdio.h>

typedef struct
{
  int thing1;
  float thing2;
  float thing3;
} data;

int main(void)
{
  data info;
  data *ptr;

  ptr=&info;

  info.thing1 = 100;
  (*ptr).thing2 = 5.5;
  ptr->thing2 = 5.5;

  printf("%d %.2f %.2f\n", info.thing1, info.thing2, info.thing3);

  return 0;
}
