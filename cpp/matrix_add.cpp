#include <iostream>

using namespace std;

int main()
{
  int i = 0;
  int j = 0;

  int a[2][3] =
  {
    { -5, 2, 8 },
    { 1, 0, 0 }
  };

  int b[2][3] =
  {
    { 1, 0, 2 },
    { 0, 3, -6 }
  };

  int c[2][3];

  cout << "Matrix A contents:" << endl;
  for(i = 0; i < 2; i++)
  {
    for(j = 0; j < 3; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }

  cout << endl << "Matrix B contents:" << endl;
  for(i = 0; i < 2; i++)
  {
    for(j = 0; j < 3; j++)
      cout << b[i][j] << " ";
    cout << endl;
  }

  cout << endl << "Summing matrices..." << endl;
  for(i = 0; i < 2; i++)
  {
    for(j = 0; j < 3; j++)
      c[i][j] = a[i][j] + b[i][j];
  }

  cout << endl << "Sum of matrices:" << endl;
  for(i = 0; i < 2; i++)
  {
    for(j = 0; j < 3; j++)
      cout << c[i][j] << " ";
    cout << endl;
  }

  return 0;
}
