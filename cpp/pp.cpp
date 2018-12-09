#include <iostream>
#include <cstdio>

int main()
{
  char **strings[100];
  *strings = "test1";
  *strings + 1 = "test2";

  puts(*strings);
  puts(*strings + 1);
}
