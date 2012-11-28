/*
  Eric Brewer 
  Lab 3 - CS115
  9/9/08
*/

#include <iostream>
#include <cmath>

using namespace std;

const float pi = 3.14159;

int main ()
{
  float inVal = 1;
  cout << "Enter a numeric value: ";
  cin >> inVal;

  cout.setf (ios::fixed);
  cout.setf (ios::showpoint);
  cout.precision (2);

  float sqArea = inVal * inVal;
  cout << "The area of a square with side length "
       << inVal << " is " << sqArea << "." << endl;
  
  float cirArea = pi * inVal * inVal;
  cout << "The area of a circle with radius "
       << inVal << " is " << cirArea << "." << endl;
  
  float cubeVol = pow(inVal, 3);
  cout << "The volume of a cube with side length "
       << inVal << " is " << cubeVol << "." << endl;

  float sphVol = (4.0/3.0) * pi * pow(inVal, 3);
  cout << "The volume of a sphere with radius "
       << inVal << " is " << sphVol << "." << endl;

  float equTriArea = inVal * inVal * sqrt(3) / 4.0;
  cout << "The area of an equilateral triangle with side length "
       << inVal << " is " << equTriArea << "." << endl;

  return 0;
}
