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
  int x, y;
  cout << "Enter two numeric values: ";
  cin >> x >> y;

  if ((x > 0) && (y > 0))
    cout << "Both are positive." << endl;
  if ((x > 0) && (y <= 0))
    cout << "Only x is positive." << endl;
  if ((x <= 0) && (y > 0))
    cout << "Only y is positive." << endl;
  if ((x <= 0) && (y <= 0))
    cout << "Neither is positive." << endl;

  return 0;
}
