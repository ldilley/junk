#include <stdio.h>

union blob
{
  char a;     /* 1 byte */
  short b;    /* 4 bytes */
  int c;      /* 4 bytes */
  float d;    /* 4 bytes */
  /*long e;*/ /* 8 bytes */
  /*double f;*/
  /*long long g;*/
};

int main()
{
  union blob blob_instance;
  printf("%i\n", sizeof(blob_instance));
  return 0;
}
