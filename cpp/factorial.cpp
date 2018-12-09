#include <iostream>

using namespace std;

int main()
{
  int number = 0;
  int factorial = 0;

  cout << "Enter a number to get its factorial: ";
  cin >> number;
  for(factorial = number, number -= 1; number > 0; number--)
    factorial *= number;

  cout << endl << "The factorial is: " << factorial << endl;

  return 0;
}
