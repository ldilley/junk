#include <iostream>
#include <exception>

using namespace std;

int main ()
{
  try
  {
    // intentionally large to demonstrate failure
    int *some_array = new int[1000000000000000];
  }
  catch (exception &e)
  {
    cout << "Exception encountered: " << e.what() << endl;
  }
  return 0;
}
