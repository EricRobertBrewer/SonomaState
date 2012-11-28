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
  cout << "Enter a numeric value: ";
  cin >> inputVal;
  int Counter = 0;
  while (inputVal > 0)
    {
      cout << "The input value is " << inputVal << endl;
      Counter++;
      cin >> inputVal;
    }
  cout << Counter << " values were entered.\n";

  return 0;
}
