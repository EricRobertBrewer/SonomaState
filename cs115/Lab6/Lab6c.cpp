/*
Eric Brewer
9/30/08
Rivoire
Lab6c
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  cout << " * |";
  for (int a = 0; a < 13; a++)
    {
      cout << setw(4) << a;
    }
  cout << endl;
  
  cout << " --+";
  for (int d = 0; d < 13; d++)
    {
      cout << "----";
    }
  cout << endl;

  for (int b = 0; b < 13; b++)
    {
      cout << setw(2) << b << " |";
      for (int c = 0; c < 13; c++)
	{
	  cout << setw(4) << (b * c);
	}
      cout << endl;
    }

  return 0;
}
