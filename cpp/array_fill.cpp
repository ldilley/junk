#include <iostream>

using namespace std;

void fill_array(int arr[], int size);
void print_array(int arr[], int size);

int main()
{
  int size = 0;
  cout << "Enter an array size: ";
  cin >> size;
  int *arr = new int[size];
  fill_array(arr, size);
  print_array(arr, size);

  return 0;
}

void fill_array(int arr[], int size)
{
  int i = 0;
  for(i = 0; i < size; i++)
    arr[i] = i;
  return;
}

void print_array(int arr[], int size)
{
  int i = 0;
  for(i = 0; i < size; i++)
    cout << arr[i] << endl;
  return;
}
