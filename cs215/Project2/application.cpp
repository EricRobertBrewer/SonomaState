#include <iostream>
#include "polynomial.h"
using namespace std;

int main()
{
  polynomial p1;
  cout << p1 << endl;
  polynomial p2(5);
  cout << p2 << endl;
  int A[] = {1,2,3,4};
  polynomial p3(3, A);
  cout << p3 << endl;
  polynomial p4 = p3;
  cout << p4 << endl;
  cin >> p1;
  cout << p1 << endl;
  p2 = p1 + p3;
  cout << p2 << endl;
  p2 = p1 - p3;
  cout << p2 << endl;
  p2 = p1 * p3;
  cout << p3 << endl;
  
  return 0;
}
