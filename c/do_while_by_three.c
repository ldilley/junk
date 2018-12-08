#include <stdio.h>

int main(void)
{
  int i = 1;

  do
  {
    printf("%i\n", i);
    i += 3;
  }
  while(i < 100);

  return 0;
}
