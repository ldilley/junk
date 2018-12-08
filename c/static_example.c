#include <stdio.h>

int bleh; // global var

void stat_demo(void);

int main(void)
{
  register i=0;

  puts("extern\tstatic");
  for(i=0; i<10; i++)
    stat_demo();

  return 0;
}

void stat_demo(void)
{
  static x=0;
  extern bleh;

  printf("%d\t%d\n", bleh++, x++);

  return;
}
