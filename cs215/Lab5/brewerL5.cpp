#include   <iostream>
#include   <iomanip>
#include   <fstream>
#include   <string>
#include   "Lab5.h"
using namespace std;
const int MAX = 100;
int main ()
{
  // Open file for input                                                                                                                                                                                        
  ifstream input ("words.txt");
  string inword;
  int totvowels = 0;
  int totconsonants = 0;
  int totdigits = 0;
  int totspecialchars = 0;
  
  WordData words[MAX];
  // Intitialize word counter                                                                                                                                                                                   
  int count = 0;
  // Read until array is filled or end of file is found                                                                                                                                                         
  while (count < MAX && input >> inword)
    {
      // Insert word into array                                                                                                                                                                                 
      words[count].SetWord(inword);
      // Increment counter

      totvowels += words[count].GetNumVowels();
      totconsonants += words[count].GetNumConsonants();
      totdigits += words[count].GetNumDigits();
      totspecialchars += words[count].GetNumSpecialChars();
                                                                                                                                                                                      
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

  for (int j = 0; j < 44; j++)
    {
      cout << '-';
    }
  cout << endl;

  //Print totals  
  cout << setw(12) << left << "Total";
  cout << setw(8) << right << totvowels;
  cout << setw(8) << right << totconsonants;
  cout << setw(8) << right << totdigits;
  cout << setw(8) << right << totspecialchars;
  cout << endl;

  return 0;
}
