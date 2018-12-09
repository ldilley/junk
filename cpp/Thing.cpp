#include <iostream>

using namespace std;

class Thing
{
  public:
    static int count;

    Thing()
    {
      count++;
      cout << "Object #" << count << " added." << endl;
      return;
    }

    Thing(string name)
    {
      count++;
      this->name = name;
      cout << "Object #" << count << " added." << endl;
      return;
    }

    ~Thing()
    {
      count--;
      cout << "Object removed. " << count << " objects remain." << endl;
      return;
    }

    string get_name()
    {
      return name;
    }

    void set_name(string name)
    {
      this->name = name;
      return;
    }

    private:
      string name;
};

int Thing::count = 0;

int main()
{
  Thing *thing1 = new Thing();
  Thing *thing2 = new Thing();
  Thing *thing3 = new Thing("Foo");
  cout << thing3->get_name() << endl;
  delete thing2;

  return 0;
}
