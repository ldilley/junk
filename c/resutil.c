#include <stdio.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>

int main()
{
  int x, y;
  struct rusage resutil;
  memset(&resutil, 0, sizeof(resutil));
  getrusage(RUSAGE_SELF, &resutil);
  printf("Memory usage: %dKB\n", resutil.ru_maxrss);
  double arr[1000][1000];
  for(x = 0; x < 1000; x++)
  {
    for(y = 0; y < 1000; y++)
      arr[x][y] = x + y;
  }
  getrusage(RUSAGE_SELF, &resutil);
  printf("Memory usage: %dKB\n", resutil.ru_maxrss);

  return 0;
}
