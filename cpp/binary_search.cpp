#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

int binary_search(int data[], int num_elements, int search_key);

int main()
{
  int key = 0;
  int data[] = { 1, 4, 5, 6, 9, 14, 21, 23, 28, 31, 35, 42, 46, 50, 53, 57, 62, 63, 65, 74, 79, 89, 95 };

  for(;;)
  {
    cout << "Enter search key (or '-1' to exit): ";
    while(!(cin >> key))
    {
      cout << "Invalid input!" << endl;
      cout << "Enter search key (or '-1' to exit): ";
      cin.clear();
      //cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.ignore();
    }
    if(key == -1)
      exit(0);
    cout << binary_search(data, sizeof(data) / sizeof(int), key);
  }

  return 0;
}

int binary_search(int data[], int num_elements, int search_key)
{
  bool found = false;
  int index = 0;

  while(!found)
    if(search_key < data[num_elements / 2]

  return index; // implementation incomplete / always returns 0 due to slothfulness
}
