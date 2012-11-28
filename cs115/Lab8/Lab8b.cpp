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
int InputNumScores(ifstream& input);
float ComputePctScore(ifstream& input, int numScores);
int main()
{
  ifstream input;
  int numScores;
  numScores = InputNumScores(input);
  cout << "Your percent is "
       << ComputePctScore(input, numScores) << "%\n";
  input.close();
  return 0;
}
int InputNumScores(ifstream& input)
{
  int numScores;
  string fileName = "c";
  cout << "What file will you be reading from, sir or madame?\n";
  cin >> fileName;
  input.open(fileName.c_str());
  if (input.fail())
    {
      cout << "File read error.\n";
      exit(1);
    }
  input >> numScores;
  return numScores;
}
float ComputePctScore(ifstream& input, int numScores)
{
  int total=0, possible=0;
  int score, high;
  float pct;
  while (!input.eof())
    {
      input >> score >> high;
      total += score;
      possible += high;
    }
  pct = 100.0 * total/possible;
}
