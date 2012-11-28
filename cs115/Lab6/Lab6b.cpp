/*
Eric Brewer
9/30/08
Rivoire
Lab6b
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int i, j, k;
  int line = 1;
  for (i = 1; i <= 3; i++)
    {
      for (j = 1; j <= 4; j++)
	{
	  for (k = 3; k >= 1; k--)
	    {
	      cout << setw(2) << i << setw(2) << j << setw(2) << k << "\t";
	    }
	  cout << endl;
	}
      cout << endl;
    }
  cout << endl;

  return 0;
}
