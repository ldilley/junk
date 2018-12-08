#include <stdio.h>
#include <stdlib.h>

char *concat(char *arr1, char *arr2)
{
  int count1 = 0;
  int count2 = 0;
  int size = 0;
  int i = 0;
  int j = 0;

  while(arr1[count1] != '\0')
    count1++;

  while(arr2[count2] != '\0')
    count2++;

  size = count1 + count2 + 1; /* +1 for the space */
  char *arr3 = (char *)malloc(sizeof(char) * size);

  for(i = 0; i < count1; i++)
    arr3[i] = arr1[i];

  /* add a space between the two words and increment 'i' to account for this addition */
  arr3[i] = ' ';
  i++;

  for(/* i has the same value where it left off above */ ; i < size; i++)
  {
    arr3[i] = arr2[j];
    j++;
  }

  return arr3;
}

int main()
{
  char *arr1 = "Hello";
  char *arr2 = "World!";
  char *arr3 = concat(arr1, arr2);
  puts(arr3);
  free(arr3);

  return 0;
}
