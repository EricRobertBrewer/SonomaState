/*
Eric Brewer
10/14/08
Rivoire
Lab8b
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
void InputNumScores(ifstream& input);
float ComputePctScore(ifstream& input);
int main()
{
  ifstream input;
  InputNumScores(input);
  cout << "Your percent is "
       << ComputePctScore(input) << "%\n";
  input.close();
  return 0;
}
void InputNumScores(ifstream& input)
{
  string fileName = "c";
  cout << "What file will you be reading from, sir or madame?\n";
  cin >> fileName;
  input.open(fileName.c_str());
  if (input.fail())
    {
      cout << "File read error.\n";
      exit(1);
    }
}
float ComputePctScore(ifstream& input)
{
  int total=0, possible=0;
  int score, high;
  float pct;
  input >> score >> high;
  while (!input.eof())
    {
      total += score;
      possible += high;
      input >> score >> high;
    }
  pct = 100.0 * total/possible;
}
