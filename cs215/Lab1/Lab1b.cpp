/*
Eric Brewer
1/28/09
CS215
Lab1
*/
#include <iostream>
#include           <string>
using namespace std;
int main ()
{
  int i;
  float f;
  char c;
  string s;
  bool failflag;
  cout << "Enter line of data: ";
  cin >> i;
  failflag = cin.fail();
  // Set breakpoint 1 here
  while (i != 0)
    {
      cin >> f >> c >> s;
      failflag = cin.fail();
      // Set breakpoint 2 here
      cout << "The output is: ";
      cout << i << ' ' << f << ' ';
      cout << c << ' ' << s << endl;
      cout << "Enter line of data: ";
      cin >> i;
      failflag = cin.fail();
      // Set breakpoint 3 here
      cout << "At end of loop\n";
    }
  return 0;
}
