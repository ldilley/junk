#include <stdio.h>

typedef struct
{
  int hours;
  int minutes;
  int seconds;
} time;

int main(void)
{
  time current_time;
  time *p_time;

  p_time = &current_time;

  p_time->hours = 12;
  (*p_time).minutes = 45;
  current_time.seconds = 30;

  printf("%d:%d:%d\n", current_time.hours, p_time->minutes, (*p_time).seconds);

  return 0;
}
