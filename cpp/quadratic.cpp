#include <iostream>
#include <cmath>

using namespace std;

bool quadratic_formula(float a, float b, float c, float r1, float i1, float r2, float i2);

int main()
{
  quadratic_formula(1.0, 1.0, -6.0, 0.0, 0.0, 0.0, 0.0);

  return 0;
}

bool quadratic_formula(float a, float b, float c, float r1, float i1, float r2, float i2)
{
  int x = 0;
  x = b + sqrt(b * b - 4 * a * c) / 2 * a;

  cout << x << endl;

  return true;
}
