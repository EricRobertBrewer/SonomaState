/*
Eric Brewer
9/23/08
Rivoire - CS115
Lab5
*/

#include <iostream>
using namespace std;

int main ()
{
  int inputVal = 1;
  cout << "Enter a numeric value:";
  cin >> inputVal;
  
  while (cin.fail())
    {
      cin.clear();
      cin.ignore(80, '\n');
      cout << "cin.fail() = " << cin.fail() << endl;
      cout << "Try again." << endl;
      cin >> inputVal;
    }
  cout << "You entered " << inputVal << '.' << endl;

  return 0;
}
