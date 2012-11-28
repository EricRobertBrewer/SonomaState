#include   <iostream>
#include   <iomanip>
#include   <fstream>
#include   <string>
#include   "Lab4.h"
using namespace std;
const int MAX = 100;
int main ()
{
  // Open file for input
  ifstream input ("words.txt");
  string inword;
  WordData words[MAX];
  // Intitialize word counter
  int count = 0;
  // Read until array is filled or end of file is found
  while (count < MAX && input >> inword)
    {
      // Insert word into array
      words[count].SetWord(inword);
      // Increment counter
      count ++;
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
  for (int i = 0; i < count; i++)
    {
      // Print data for word
      words[i].WriteData(cout);
      cout << endl;
    }
  return 0;
}
