#include <iostream>
#include <fstream>
#include "LList2.tmp"
#include "Fraction.h"

using namespace std;

// Add a global variable for holding the sum of the fractions here
fraction sum;
 
// Add function prototype here
void FindSum(const fraction & F);

int main ()
{
  ifstream input ("Lab10.in");
  fraction one;
  LList2 <fraction> FL;
  
  while (input >> one)
    FL.InsertLast (one);
  cout << "The fractions are: ";
  cout << FL << endl;
  
// Add code to find the sum of the fractions in the list FL here
  FL.Forward(FindSum);

// Add code to print the sum here
  cout << sum << endl;

  return 0;
}

// Add function implementation here
void FindSum(const fraction & F)
{
  sum = sum + F;
}

