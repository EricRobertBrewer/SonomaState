/*
Eric Brewer
9/23/08
Rivoire
Lab5
*/

#include <iostream>
using namespace std;

int main()
{
  int ctr;
  for (ctr = 1; ctr <= 3; ctr++)
    {
      cout << "The value of ctr is " << ctr << endl;
    }
  for (ctr = 0; ctr < 3; ctr++)
    {
      cout << "The value of ctr is " << ctr << endl;
    }
  for (ctr = 3; ctr > 0; ctr--)
    {
      cout << "The value of ctr is " << ctr << endl;
    }
  for (ctr = 3; ctr >= 0; ctr--)
    {
      cout << "The value of ctr is " << ctr << endl;
    }
  for (ctr = 0; ctr <= 3; ctr +=2)
    {
      cout << "The value of ctr is " << ctr << endl;
    }

  return 0;
}
