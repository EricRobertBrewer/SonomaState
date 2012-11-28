/*
e.cpp
Team 13
Eric Brewer, Vinh Gruenhagen, Stephen Gulland
 */

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
#include <fstream>
#include <cmath>

#define DEBUG 1
#define debug if(DEBUG) cout

int fib( int n, int m );

int main()
{
  int temp;
  for (int i = 0; i < 11; i++)
    {
      temp = fib(i, 0);
      cout << "(" << i << ") " << temp << endl;
    }
  temp = log(8)/log(2);
  cout << temp << endl;
  return 0;

}

int fib( int n, int m)
{
  if(n == 0)
    return m;
  if(n == 1)
    return m+1;
  return fib(n-1, m) + fib(n-2, m);
}
