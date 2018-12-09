#include <iostream>

using namespace std;

int main()
{
  int arr[10];
  int i = 0;
  int iteration = 0;
  int tmp = 0;
  int smallest_number = 0;
  int smallest_index = 0;
  bool done = false;

  cout << "Enter 10 unsorted integers: " << endl;
  for(i = 0; i < 10; i++)
  {
    cout << "[" << i << "] = ";
    cin >> arr[i];
  }

  cout << "Sorting..." << endl;

  while(!done)
  {
    smallest_number = arr[iteration];
    for(i = iteration; i < 10; i++)
    {
      if(smallest_number < arr[i])
        continue;
      else
      {
        smallest_number = arr[i];
        smallest_index = i;
      }
    }
    tmp = arr[iteration];             // temporarily hold number being swapped out
    arr[smallest_index] = tmp;        // perform the swap
    arr[iteration] = smallest_number;
    iteration++;
    if(iteration >= 10)
      done = true;
  }

  cout << "Sorted array: " << endl;
  cout << "[ ";
  for(i = 0; i < 10; i++)
    cout << arr[i] << " ";
  cout << "]" << endl;

  return 0;
}
