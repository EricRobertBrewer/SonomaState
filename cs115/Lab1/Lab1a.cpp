#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main ()
{
  string message = "Hello";
  string name;

  cout << "Hello, what is your name? ";
  cin >> name;
  message = message + " " + name;

  for (float i = 0; i < 6.28; i = i+0.3)
    {
      int spaces = int (30 + 20 * sin (i));
      for (int j = 0; j < spaces; j++)
	cout << ' ';
      cout << message << endl;
    }

  return 0;
} 
