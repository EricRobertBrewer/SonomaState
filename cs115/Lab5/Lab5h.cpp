/*
Eric Brewer
9/23/08
Rivoire - CS115 - Tues. Lab
Lab 5
*/

#include <iostream>
using namespace std;

int main()
{
  int i, j;
  for (i = 1; i <= 4; i++)
    {
      for (j = 0; j < i; j++)
	{
	  cout << i << ',' << j << '\t';
	}
      cout << endl;
    }
  cout << endl;

  return 0;
}
