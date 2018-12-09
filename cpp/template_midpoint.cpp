#include <iostream>
#include "temp.h"

using namespace std;

template <typename T>
Interval<T>::Interval()
{
  a = T();
  b = T();
}

template <typename T>
Interval<T>::Interval(T start, T end)
{
  a = start;
  b = end;
}

template <typename T>
T Interval<T>::midpoint()
{
  return (a + b) * 0.5;
}

int main()
{
  int a = 5;
  int b = 5;
  float c = 5.5;
  float d = 5.5;

  Interval<int> intval(a , b);
  Interval<float> floatval(c, d);

  cout << intval.midpoint() << endl;
  cout << floatval.midpoint() << endl;

  return 0;
}
