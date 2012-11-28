/*
Eric Brewer
9/16/08
Lab 4  -  If-else staements
Rivoire
*/

#include <iostream>

using namespace std;

int main ()
{
  float Val = 1.0;
  cout << "Enter a numeric value: ";
  cin >> Val;
 
  if (Val < 0)
    {
      cout << "The old value is " << Val << '.' << endl;
      Val += 3;
      cout << "The new value is " << Val << '.' << endl;
    }
 
  if (Val > 0)
    {
      cout << "The old value is " << Val << '.' << endl;
      Val -=3;
      cout << "The new value is " << Val << '.' << endl;
    }

  if (Val == 0)
    {
      cout << "The old value is " << Val << '.' << endl;
      Val +=2;
      cout << "The new value is " << Val << '.' << endl;
    }

  return 0;
}
