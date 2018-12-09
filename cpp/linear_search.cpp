#include <iostream>

using namespace std;

int main()
{
  int arr[] = { 7, 3, 32, 2, 55, 34, 6, 13, 29, 22, 11, 9, 1, 5, 42, 39, 8 };
  int i = 0;
  int search_number = 0;
  bool was_found = false;
  int at_index = 0;

  cout << "Array contents: " << endl;
  cout << "[ ";
  for(i = 0; i < sizeof(arr) / sizeof(int); i++)
    cout << arr[i] << " ";
  cout << "]" << endl;

  cout << "Enter a number to search for: ";
  cin >> search_number;

  for(i = 0; i < sizeof(arr) / sizeof(int); i++)
  {
    if(arr[i] == search_number)
    {
      was_found = true;
      at_index = i;
      break;
    }
    else
      continue;
  }

  if(was_found)
    cout << search_number << " was found at position: " << at_index << endl;
  else
    cout << search_number << " was not found." << endl;

  return 0;
}
