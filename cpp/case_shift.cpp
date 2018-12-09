#include <iostream>
#include <cctype>

using namespace std;

char toUpperCase(char input);
char toLowerCase(char input);

int main()
{
  char input = '\0';

  cout << "Enter a letter to make upper case: ";
  cin >> input;
  cout << toUpperCase(input) << endl;

  cout << "Enter a letter to make lower case: ";
  cin >> input;
  cout << toLowerCase(input) << endl;

  return 0;
}

char toUpperCase(char input)
{
  int i = 0;
  char c = '\0';

  for(i = 65; i < 91; i++)
  {
    if(static_cast<int>(input) == i)
      c = input;
  }

  for(i = 97; i < 123; i++)
  {
    if(static_cast<int>(input) == i)
      c = toupper(input);
  }

  return c;
}

char toLowerCase(char input)
{
  int i = 0;
  char c = '\0';

  for(i = 65; i < 91; i++)
  {
    if(static_cast<int>(input) == i)
      c = tolower(input);
  }

  for(i = 97; i < 123; i++)
  {
    if(static_cast<int>(input) == i)
      c = input;
  }

  return c;
}
