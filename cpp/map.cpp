#include <iostream>
#include <map>

using namespace std;

int main()
{
  map<const char *, int> amap;
  amap["test"] = 275;
  cout << amap["test"] << endl;

  return 0;
}
