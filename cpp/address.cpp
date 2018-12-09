#include <cstddef> // NULL
#include <iostream>

using namespace std;

int main()
{
  int a = 10;
  int *pa = &a;
  int **ppa = &pa;
  cout << ppa << endl;   // prints memory address of 'ppa'
  cout << *ppa << endl;  // prints memory address of 'pa'
  cout << pa << endl;    // prints memory address of 'pa' to show it is the same as above
  cout << **ppa << endl; // prints value of a by double dereference
  return 0;
}
