#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 128

char *concat_string(char str1[], char str2[], int size, char *ptr);

int main(void)
{
  char str1[MAX_SIZE];
  char str2[MAX_SIZE];
  char *ptr;

  printf("Enter string #1: ");
  gets(str1);
  printf("Enter string #2: ");
  gets(str2);

  printf("Concatenated string: %s\n", concat_string(str1, str2, MAX_SIZE, ptr));
  free(ptr);

  return 0;
}

char *concat_string(char str1[], char str2[], int size, char *ptr)
{
  int i, len1 = 0, len2 = 0;
  char *str3;

  for(i = 0; i < size; i++)
  {
    len1++;
    if(str1[i] == '\0')
    {
      len1--;
      break;
    }
  }

  for(i = 0; i < size; i++)
  {
    len2++;
    if(str2[i] == '\0')
    {
      len2--;
      break;
    }
  }

  ptr = (char *)malloc((len1 + len2 + 2)* sizeof(char)); /* +2 for the space separator and null terminator */
  if(ptr == NULL)
  {
    puts("Could not allocate memory for concatenated string.");
    exit(1);
  }

  str3 = ptr;

  for(i = 0; i < len1; i++)
    *str3++ = str1[i];

  *str3++ = ' ';

  for(i = 0; i < len2; i++)
    *str3++ = str2[i];

  *str3 = '\0';

  return ptr;
}
