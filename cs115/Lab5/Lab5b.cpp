/*
Eric Brewer
9/23/08
Rivoire - CS115
Lab 5
*/

#include <iostream>
using namespace std;

int main()
{
  int inputVal = 1;
  int Counter = 1;
  while (Counter <= 5)
    {
      cout << "Enter a numeric value: ";
      cin >> inputVal;
      if (inputVal % 2)
	{
	  cout << inputVal << " is odd.\n";
	}
      else
	{
	  cout << inputVal << " is even.\n";
	}
    }

  return 0;
}
