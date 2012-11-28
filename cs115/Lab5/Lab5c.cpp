/*
Eric Brewer
9/23/08
Rivoire - CS115
Lab5 - All about loops
*/

#include <iostream>
using namespace std;

int main()
{
  int inputVal = 1;
  cout << "Enter a numeric value: ";
  cin >> inputVal;
  int Counter = 1;
  int Total = 0;
  while (Counter <= inputVal)
    {
      if (Counter % 2)
	Total = Total - Counter;
      else
	Total = Total + Counter;
      Counter++;
    }
  cout << "The total value is " << Total << endl;

  return 0;
}

     
