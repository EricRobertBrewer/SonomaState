/*
Eric Brewer
11/18/08
Rivoire
Lab 12
*/

#include <iostream>
using namespace std;
int increment(int x);
int increment(int *x);
int main( ) {
  int a = 5;
  char c = 'p';
  int * a_ptr = &a;
  char* c_ptr = &c;
  cout << "Address of a = " << a_ptr << endl;
  cout << "Address of c = " << (void *)c_ptr << endl;
  cout << "Contents of a = " << *a_ptr << endl;
  cout << "Contents of c = " << *c_ptr << endl;
  cout << increment(a) << endl;
  cout << a << endl;
  cout << increment(a_ptr) << endl;
  cout << a << endl;

  return 0;
}
int increment(int x)
{
  return ++x;
}
int increment(int *x)
{
  return ++(*x);
}
