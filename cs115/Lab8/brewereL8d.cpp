/*
Eric Brewer
10/14/08
Rivoire
Lab8d
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
void OpenInputFile(ifstream& infile);
bool OneProblem(ifstream& input);
bool PrintQuestion(ifstream& input);
void CheckAnswer(char answer, char guess);
int main ()
{
  ifstream input;
  OpenInputFile(input);
  do
    {
       OneProblem(input);
    } while(OneProblem(input));
  input.close();
  return 0;
}
void OpenInputFile(ifstream& infile)
{
  infile.open("problems.in");
  if (infile.fail())
    {
      cout << "Could not open problems.in\n";
      exit(1);
    }
}
bool OneProblem(ifstream& input)
{
  string line;
  char   answer, guess;
  if (!PrintQuestion(input))
    {
      return false;
    }
  input >> answer;
  getline(input, line);
  cout << "Enter the correct answer: ";
  cin >> guess;
  CheckAnswer(answer, guess);
  return true;
}
bool PrintQuestion(ifstream& input)
{
  string line;
  getline(input, line);
  if (input.fail())
    {
      return false;
    }
  cout << line << endl;
  for (int i=0; i<4; i++)
    {
      getline(input, line);
      cout << line << endl;
    }
  return true;
}
void CheckAnswer(char answer, char guess) {
  if (guess == answer)
    {
      cout << "Correct!\n";
    }
  else
    {
      cout << "Incorrect. The correct answer is "
	   << answer << ".\n";
    }
}
