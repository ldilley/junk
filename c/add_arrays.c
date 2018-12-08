#include <stdio.h>

#define ARR_SIZE 5

void add_arrays(int arr1[], int arr2[], int arr3[], int size);

int main(void)
{
  int arr1[ARR_SIZE];
  int arr2[ARR_SIZE];
  int arr3[ARR_SIZE];
  int i;

  puts("On first array...");
  for(i = 0; i < ARR_SIZE; i++)
  {
    printf("Enter element #%d: ", i);
    scanf("%d", &arr1[i]);
  }

  puts("On second array...");
  for(i = 0; i < ARR_SIZE; i++)
  {
    printf("Enter element #%d: ", i);
    scanf("%d", &arr2[i]);
  }

  add_arrays(arr1, arr2, arr3, ARR_SIZE);

  for(i = 0; i < ARR_SIZE; i++)
    printf("Summed element #%d: %d\n", i, arr3[i]);

  return 0;
}

void add_arrays(int arr1[], int arr2[], int arr3[], int size)
{
  int i;

  for(i = 0; i < size; i++)
    arr3[i] = arr1[i] + arr2[i];

  return;
}
