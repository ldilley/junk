#include <stdio.h>
#include <stdarg.h>
#include <string.h>

char buffer[2048] = "";

void handle_vargs(int arg_count, ...)
{
  va_list args;
  int i;
  va_start(args, arg_count);
  for(i = 0; i < arg_count; i++)
  {
    strcat(buffer, va_arg(args, char *));
    strcat(buffer, " ");
  }
  va_end(args);
  puts(buffer);
  return;
}

int main()
{
  handle_vargs(4, "foo", "bar", "baz", "bat");
  handle_vargs(1, "kudzu");
  return 0;
}
