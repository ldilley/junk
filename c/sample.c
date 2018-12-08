#include <stdio.h>

/* Returns total of two arrays of varying sizes */
int sum_arrays(int *arr1, int size1, int *arr2, int size2)
{
  int i = 0;
  int total = 0;

  for(i = 0; i < size1; i++)
    total += arr1[i];

  for(i = 0; i < size2; i++)
    total += arr2[i];

  return total;
}

/* Adds two arrays of same size */
int add_arrays(int *arr1, int *arr2, int size, int *arr3)
{
  int i = 0;

  for(i = 0; i < size; i++)
    arr3[i] = arr1[i] + arr2[i];

  return *arr3;
}

int main()
{
  int i = 0;
  char *char_ptr;
  int cost;
  int *p_cost = &cost;
  cost = 100;
  *p_cost = 100;
  printf("%i %i\n", cost, *p_cost);
  float radius;
  float *p_radius = &radius;
  int data[10];
  data[3] = 100;
  int *p_data = data;
  *(p_data + 2) = 100;

  /* Total up two arrays */
  int arr1[10] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
  int arr2[5] = { 1, 1, 1, 1, 1};
  printf("%i\n", sum_arrays(arr1, 10, arr2, 5));

  /* Add two arrays of same size */
  int arr3[5] = { 1, 2, 4, 8, 16 };
  int arr4[5] = { 1, 2, 4, 8, 16 };
  int arr5[5];
  add_arrays(arr3, arr4, 5, arr5);
  for(i = 0; i < 5; i++)
    printf("%i\n", arr5[i]);

  return 0;
}
