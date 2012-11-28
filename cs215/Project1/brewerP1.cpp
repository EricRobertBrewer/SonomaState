/*
Project1.cpp
Eric Brewer
2/17/09
CS215
Project1 - Binomial test:
 This program tests the capabilities
 of binomial.h. This only makes sure
 that the functions and prototypes of
 binomial.h have been implemented 
 correctly.
*/

#include <iostream>
#include "binomial.h"

using namespace std;

int main ()
{
  binomial b1, b2, b3;
  init(b1);
  init(b2);
  init(b3,1,2);

  output(cout, b3);
  cout << endl;
  
  input(cin, b1);
  input(cin, b2);
  
  b3 = sum(b1, b3);
  output(cout, b3);
  cout << endl;
  
  b3 = difference(b1, b2);
  output (cout, b3);
  cout << endl;
  
  return 0;
}
