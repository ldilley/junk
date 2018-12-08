/* Demonstrates recursion */

#include <stdio.h>

unsigned int f, x;
unsigned int factorial(unsigned int a);

int main(void)
{
  printf("Enter an integer value between 1 and 8: ");
  scanf("%i", &x);

  if (x > 8 || x < 1)
    printf("Only values between 1 and 8 are accepted.\n");
  else
  {
    f = factorial(x);
    printf("%u factorial equals %u\n", x ,f);
  }

  return 0;
}

unsigned int factorial(unsigned int a)
{
  if (a == 1)
    return 1;
  else
  {
    a *= factorial(a - 1); // function calling itself
    return a;
  }
}
