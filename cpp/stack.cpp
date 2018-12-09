#include <iostream>
#include <stack>

using namespace std;

int main()
{
  stack<char> charstack;
  string word = "";
  int i = 0;

  cout << "Enter a word: ";
  cin >> word;
  for(i = 0; i < word.length(); i++)
    charstack.push(word[i]);

  cout << "Word in reverse: " << endl;
  for(i = 0; i < word.length(); i++)
  {
    cout << charstack.top() << endl;
    charstack.pop();
  }

  return 0;
}
