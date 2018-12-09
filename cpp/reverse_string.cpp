#include <iostream>
#include <string>

using namespace std;

string reverse_string(string str);

int main()
{
  string str = "";
  cout << "Enter a string to reverse: ";
  getline(cin, str);
  cout << reverse_string(str) << endl;
  return 0;
}

string reverse_string(string str)
{
  char crstr[str.length()];
  int i = 0;
  int j = str.length() - 1;
  for(i = 0; i < str.length(); i++, j--)
    crstr[i] = str[j];
  string rstr = crstr;
  return rstr;
}
