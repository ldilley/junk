#include <iostream>

using namespace std;

int main()
{
  int amount = 0;
  int i = 0;
  int total = 0;

  cout << "How many numbers do you want to average? ";
  cin >> amount;
  int arr[amount];
  for(i = 0; i < amount; i++)
  {
    cout << "Enter amount #" << i << ": ";
    cin >> arr[i];
    total += arr[i];
  }

  cout << "The average is: " << total / amount << endl;

  return 0;
}
