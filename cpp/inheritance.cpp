#include <iostream>
#include <string>

using namespace std;

class GrandParent
{
  public:
    GrandParent() { cout << "GrandParent()" << endl; }
    ~GrandParent() { cout << "~GrandParent()" << endl; }
};

class Parent : public GrandParent
{
  public:
    Parent() { cout << "Parent()" << endl; }
    ~Parent() { cout << "~Parent()" << endl; }
};

class Child : public Parent
{
  public:
    Child() { cout << "Child()" << endl; }
    ~Child() { cout << "~Child()" << endl; }
};

int main()
{
  Child child;
}
