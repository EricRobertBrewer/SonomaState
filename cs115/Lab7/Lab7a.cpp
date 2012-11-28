/*
Eric Brewer
9/30/08
Rivoire
Lab6e
*/

#include <iostream>
using namespace std;

void Function1 (char parameter);

int Function2 (int parameter);

float Function3 (int parameter);

int main ()
{
  int Value1;
  int Value2;
  cout << "calling Function1\n";
  Function1 ('a');
  cout << "calling Function2\n";
  Value1 = Function2 (4);
  cout << "result of Function2: " << Value1 << endl;
  cout << "calling Function3\n";
  Value2 = Function3 (Value1);
  cout << "result of Function3: " << Value2 << endl;

  return 0;
}

void Function1 (char parameter)
{
  cout << "executing Function1\n";
  cout << "the character" << parameter << " was passed to this function\n";
  cout << "returning from Function1\n";
}
int Function2 (int parameter)
{
  cout << "executing Function2\n";
  int returnValue = 5 + parameter;
  cout << "returning from Function2\n";
  return returnValue;
}
float Function3 (int parameter)
{
  cout << "executing Function3\n";
  float returnValue = parameter / 2;
  cout << "returning from Function3\n";
  return returnValue;
}
