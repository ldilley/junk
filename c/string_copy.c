#include <stdio.h>

#define MAX_SIZE 128

void copy_string(char str1[], char str2[], int size);

int main(void)
{
  char str1[MAX_SIZE];
  char str2[MAX_SIZE];

  printf("Enter your full name: ");
  gets(str1);

  copy_string(str1, str2, MAX_SIZE);

  puts(str2);

  return 0;
}

void copy_string(char str1[], char str2[], int size)
{
  int i;

  for(i = 0; i < size; i++)
    str2[i] = str1[i];

  return;
}
