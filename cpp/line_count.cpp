#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  string line = "";
  int line_count = 0;
  ifstream in_file(argv[1]); // argv[1] should be the file argument

  while(!in_file.eof())
  {
    getline(in_file, line);
    line_count++;
  }
  in_file.close();

  cout << argv[1] << " contains " << line_count << " lines." << endl;

  return 0;
}
