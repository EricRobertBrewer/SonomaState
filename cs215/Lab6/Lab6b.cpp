/*
Eric Brewer
3/4/09
CS215
Lab6b
*/

#include   <iostream>
#include   <iomanip>
#include   <fstream>
#include   <string>
#include   <vector>
#include   "Lab6.h"
using namespace std;
int main ()
{
  // Open file for input
  ifstream input ("words.txt");
  string inword;

  int totvowels = 0;
  int totconsonants = 0;
  int totdigits = 0;
  int totspecialchars = 0;

  // create a vector to hold a collection of WordData objects
  vector <WordData> words;
  // Intitialize word counter
  // Read until array filled or end of file
  while (input >> inword)
    {
      // Insert word into a WordData object
      WordData oneword;
      oneword.SetWord(inword);
      // Push oneword onto the end of the words vector
      words.push_back (oneword);

      //totvowels += words[count].GetNumVowels();
      //totconsonants += words[count].GetNumConsonants();
      //totdigits += words[count].GetNumDigits();
      //totspecialchars += words[count].GetNumSpecialChars();

    }
  // Close inout file
  input.close();
  // Print report header
  cout << setw (12) << left << "Word";
  cout << setw (8) << right << "Vowels";
  cout << setw (8) << right << "Const.";
  cout << setw (8) << right << "Digits";
  cout << setw (8) << right << "Special";
  cout << endl;
  // Loop through all words in array
  for (int i = 0; i < words.size(); i++)
    {
      // Print data for word
      words[i].WriteData(cout);
      cout << endl;

      totvowels += words[i].GetNumVowels();
      totconsonants += words[i].GetNumConsonants();
      totdigits += words[i].GetNumDigits(); 
      totspecialchars += words[i].GetNumSpecialChars();
    }

  cout << setw(12) << left << "Total";
  cout << setw(8) << right << totvowels;
  cout << setw(8) << right << totconsonants;
  cout << setw(8) << right << totdigits;
  cout << setw(8) << right << totspecialchars;
  cout << endl;
  
  return 0;
}
