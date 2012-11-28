/*
Program: Lab2
Author: Eric Robert Brewer
Date: Fall2008
Description:This program will be used to test input
  and output for different variable types.
*/

#include <iostream>
#include <string>
using namespace std;

int main ()
{
  int ival = 0;
  float fval = 0.0;
  char cval = '?';
  string sval = "???";
  cout << "Enter some data: ";
  cin >> ival >> fval >> cval >> sval;
  cout << "The integer value is: " << ival << endl;
  cout << "The float value is: " << fval << endl;
  cout << "The character value is: " << cval << endl;
  cout << "The string value is: " << sval << endl;
  cout << "The value of cin.fail() is: " << cin.fail() << endl;

  return 0;
}
