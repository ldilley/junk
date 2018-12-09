//#define NDEBUG // disables all asserts in code if defined
#include <cassert>
#include <cstddef>

int main()
{
  int *ptr = NULL;
  assert(ptr != NULL); // this will fail
  return 0;
}
