/*
Eric Brewer
1/28/09
CS215
Lab1
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  string v;
  cout << "Enter the data set input: ";
  cin >> v;
  cout << v << (cin.fail() ? "true" : "false") << endl;
  cin >> v;
  cout << v << (cin.fail() ? "true" : "false") << endl;
  cin >> v;
  cout << v << (cin.fail() ? "true" : "false") << endl;

  return 0;
}
