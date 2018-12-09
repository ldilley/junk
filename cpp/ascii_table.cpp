#include <iostream>

using namespace std;

int main()
{
  int i = 0;
  int width = 1;
  const int MAX_WIDTH = 10;

  for(i = 33; i < 255; i++, width++)
  {
    cout << i << ": " << static_cast<char>(i) << " ";
    if(width >= MAX_WIDTH)
    {
      width = 0;
      cout << endl;
    }
  }
  cout << endl;

  return 0;
}
