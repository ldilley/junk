#include <iostream>
#include <cmath>

using namespace std;

float arc_tan(float y, float x);

int main()
{
  float x, y;

  cout << "Enter x value: ";
  cin >> x;
  cout << "Enter y value: ";
  cin >> y;

  cout << arc_tan(y, x) << endl;

  return 0;
}

float arc_tan(float y, float x)
{
  float theta = 0.0;

  if(x < 0)
    theta = atanf(y / x) * 180 / 3.14 + 180;
  else
    theta = atanf(y / x) * 180 / 3.14;

  return theta;
}
