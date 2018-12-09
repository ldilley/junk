#include <iostream>
#include <vector>

using namespace std;

void fill_array(vector<int> &vec);
void print_array(vector<int> &vec);

int main()
{
  int size = 0;
  cout << "Enter a vector size: ";
  cin >> size;
  vector<int> vec(size);
  fill_array(vec);
  print_array(vec);

  return 0;
}

void fill_array(vector<int> &vec)
{
  int i = 0;
  for(i = 0; i < vec.size(); i++)
    vec[i] = i;
  return;
}

void print_array(vector<int> &vec)
{
  int i = 0;
  for(i = 0; i < vec.size(); i++)
    cout << vec[i] << endl;
  return;
}
