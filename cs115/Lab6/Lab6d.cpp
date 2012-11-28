/*
Eric Brewer 
9/30/08
Rivoire
Lab6d
*/

#include <iostream>
#include <cmath>

using namespace std;

const float pi = 3.14159;

int main ()
{
  char choice = 'x';
  float inVal = 1;

  do
    {
      cout << "Would you like to" << endl;
      cout << "a. Calculate the area of a square?" << endl;
      cout << "b. Calculate the area of a circle?" << endl;
      cout << "c. Calculate the volume of a cube?" << endl;
      cout << "d. Calculate the volume of a sphere?" << endl;
      cout << "e. Calculate the area of an equilateral triangle?" << endl;
      cout << "q. Quit." << endl;

      cin >> choice;

      if (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'e' && choice != 'q')
	{
	  cout << "Invalid input" << endl;
	  choice = 'x';
	}

  if (choice == 'a')
    {
      cout << "Length of side: ";
      cin >> inVal;
      cout << endl;
  float sqArea = inVal * inVal;
  cout << "The area of a square with side length "
       << inVal << " is " << sqArea << "." << endl;
    }

  if (choice == 'b')
    {
      cout << "Length of radius: ";
      cin >> inVal;
      cout << endl;
  float cirArea = pi * inVal * inVal;
  cout << "The area of a circle with radius "
       << inVal << " is " << cirArea << "." << endl;
    }

  if (choice == 'c')
    {
      cout << "Length of edge: ";
      cin >> inVal;
      cout << endl;
  float cubeVol = pow(inVal, 3);
  cout << "The volume of a cube with side length "
       << inVal << " is " << cubeVol << "." << endl;
    }

  if (choice == 'd')
    {
      cout << "Length of radius: ";
      cin >> inVal;
      cout << endl;
  float sphVol = (4.0/3.0) * pi * pow(inVal, 3);
  cout << "The volume of a sphere with radius "
       << inVal << " is " << sphVol << "." << endl;
    }

  if (choice == 'e')
    {
      cout << "Length of side: ";
      cin >> inVal;
      cout << endl;
  float equTriArea = inVal * inVal * sqrt(3.0) / 4.0;
  cout << "The area of an equilateral triangle with side length "
       << inVal << " is " << equTriArea << "." << endl;
    }
  cout << endl;
    }
  while (choice != 'q');

    cout << "Goodbye, then!" << endl;

  return 0;
}
