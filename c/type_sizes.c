#include <stdio.h>

/* Below is no longer preferred since the const keyword was added in C99 */
/* #define BITS_IN_BYTE 8 */
const short BITS_IN_BYTE = 8;

int main(void)
{
  printf("Type\t\tByte(s)\tBits\n");
  printf("char:\t\t %d \t %d\n", sizeof(char), sizeof(char) * BITS_IN_BYTE);
  printf("short:\t\t %d \t %d \n", sizeof(short), sizeof(short) * BITS_IN_BYTE);
  printf("int:\t\t %d \t %d \n", sizeof(int), sizeof(int) * BITS_IN_BYTE);
  printf("long:\t\t %d \t %d \n", sizeof(long), sizeof(long) * BITS_IN_BYTE);
  printf("float:\t\t %d \t %d \n", sizeof(float), sizeof(float) * BITS_IN_BYTE);
  printf("double:\t\t %d \t %d \n", sizeof(double), sizeof(double) * BITS_IN_BYTE);
  printf("long long:\t %d \t %d\n", sizeof(long long), sizeof(long long) * BITS_IN_BYTE);
  printf("long double:\t %d \t %d \n", sizeof(long double), sizeof(long double) * BITS_IN_BYTE);

  return 0;
}
