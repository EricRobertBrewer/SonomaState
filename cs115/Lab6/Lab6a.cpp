/*
Eric Brewer
9/30/08
Rivoire
Lab6a
*/

#include<iostream>
using namespace std;

int main()
{
  int i, j;
  int line = 1;
  for (i = 1; i <= 5; i++)
    {
      for (j = 1; j <= 2; j++)
	{
	  cout << "Line " << line++ << ":\ti = " << i << ":\tj = " << j << endl;
	}
    }

  return 0;
}
