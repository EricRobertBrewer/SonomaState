/*
Eric Brewer
9/16/08
Lab 4  -  If-else staements
Rivoire
*/

#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
  bool b1, b2;
  float x, y;

  cout << "Enter two numeric values x and y: ";
  cin >> x >> y;

  b1 = x == y;
  b2 = x <= sqrt(y);

  cout << "b1 = " << b1 << endl;
  cout << "b2 = " << b2 << endl;

  return 0;
}
