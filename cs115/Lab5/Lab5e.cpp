/*
Eric Brewer
9/23/08
Rivoire CS115
Lab5
*/

#include <iostream>
using namespace std;

int main()
{
  int inputVal = 1;
  cout << "Enter a numeric value: ";
  cin >> inputVal;
  int Counter = 0;
  do
    {
      cout << "The input value is " << inputVal << endl;
      Counter++;
      cin >> inputVal;
    } while (inputVal > 0);
  cout << Counter << " values were entered.\n";

  return 0;
}
