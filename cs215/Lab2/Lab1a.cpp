#include <iostream>
using namespace std;
int find (int & a, int & b);
int main ()
{
  int v1, v2;
  cin >> v1 >> v2;
  while (v1 || v2)
    {
      cout << find (v1, v2);
      cout << ' ' << v1 << ' ' << v2 << endl;
      cin >> v1 >> v2;
    }
  return 0;
}

int find (int & a, int & b)
{
  int f = a < b ? a : b;
  bool flag = false;
  while (f > 1 && !flag)
    if ((a % f == 0) && (b % f == 0))
      {
	a = a/f;
	b = b/f;
	flag = true;
      }
    else
      f--;
  return f;
}
