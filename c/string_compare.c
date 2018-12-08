#include <stdio.h>

#define MAX_SIZE 128

char *string_compare(char str1[], char str2[], int size);

int main(void)
{
  char str1[MAX_SIZE];
  char str2[MAX_SIZE];

  printf("Enter a string: ");
  gets(str1);
  printf("Enter another string: ");
  gets(str2);

  printf("\"%s\" is the longer string.\n", string_compare(str1, str2, MAX_SIZE));

  return 0;
}

char *string_compare(char str1[], char str2[], int size)
{
  int i;
  int len1 = 0, len2 = 0;

  for(i = 0; i < MAX_SIZE; i++)
  {
    len1++;
    if(str1[i] == '\0')
      break;
  }

  for(i = 0; i < MAX_SIZE; i++)
  {
    len2++;
    if(str2[i] == '\0')
      break;
  }

  if(len1 > len2)
    return str1;
  else
    return str2;
}
