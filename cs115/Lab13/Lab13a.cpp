#include <iostream>

using namespace std;

int main (int argc, char * argv [])
{
  int a;
  for (a = 0; a < argc; a++)
    cout << a << ":\t" << argv[a] << endl;
  return 0;
}
