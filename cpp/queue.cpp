#include <iostream>
#include <queue>

using namespace std;

int main()
{
  queue<string> stringq;
  cout << stringq.size() << endl;
  stringq.push("test1");
  cout << stringq.size() << endl;
  cout << stringq.front() << endl;
  cout << stringq.back() << endl;
  stringq.push("test2");
  cout << stringq.size() << endl;
  cout << stringq.front() << endl;
  cout << stringq.back() << endl;

  return 0;
}
