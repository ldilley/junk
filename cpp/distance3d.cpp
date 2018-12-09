#include <iostream>
#include <cmath>

using namespace std;

float dist3(float ux, float uy, float uz, float vx, float vy, float vz);

int main()
{
  int arr1[3];
  int arr2[3];

  cout << "Enter x for object 1: ";
  cin >> arr1[0];
  cout << "Enter y for object 1: ";
  cin >> arr1[1];
  cout << "Enter z for object 1: ";
  cin >> arr1[2];

  cout << "Enter x for object 2: ";
  cin >> arr2[0];
  cout << "Enter y for object 2: ";
  cin >> arr2[1];
  cout << "Enter z for object 2: ";
  cin >> arr2[2];

  cout << "The distance between object 1 and 2 in 3D space is: " << dist3(arr1[0], arr1[1], arr1[2], arr2[0], arr2[1], arr2[2]) << endl;

  return 0;
}

float dist3(float ux, float uy, float uz, float vx, float vy, float vz)
{
  return sqrt(pow((vx - ux), 2) + pow((vy - uy), 2) + pow((vz - uz), 2));
}
