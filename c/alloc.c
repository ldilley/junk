#include <stdio.h>  /* puts() */
#include <stdlib.h> /* free(), malloc() */

int main()
{
  char *ptr = (char *)malloc(sizeof(char) * 10);
  if(ptr == NULL)
  {
    puts("Unable to allocate memory!");
    exit(1);
  }
  puts(ptr);
  free(ptr);

  return 0;
}
