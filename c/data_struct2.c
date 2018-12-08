#include <stdio.h>
#include <string.h>

typedef struct
{
  char thing[20];
} data;

int main(void)
{
  data info;

  strcpy(info.thing, "hi");

  puts(info.thing);

  return 0;
}
