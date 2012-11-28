/*
Eric Brewer
9/16/08
Lab 4  -  If-else statements
Rivoire
*/

#include <iostream>

using namespace std;

int main ()
{
  int inputVal = 1;
  cout << "Enter a numeric value: ";
  cin >> inputVal;
  if (inputVal < 0)
    {
      cout << "The value is negative." << endl;
    }
  if (inputVal > 0)
    {
      cout << "The value is positive." << endl;
    }
  if (inputVal == 0)
    {
      cout << "The value is zero." << endl;
    }

  return 0;
}
