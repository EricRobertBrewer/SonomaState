/*
Program: Lab2
Author: Eric Robert Brewer
Date: Fall 2008
Description: This program wii be used to test input
  and output for a float variable.
*/

#include <iostream>
using namespace std;

int main ()
{
  float value = 0.0;
  cout << "Enter a value: ";
  cin >> value;
  cout << "The output value is " << value << endl;
  cout << "The value of cin.fail() is " << cin.fail() << endl;

  return 0;
}