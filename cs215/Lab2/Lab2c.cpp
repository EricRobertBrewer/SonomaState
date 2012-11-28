/*
Eric Brewer
2/4/09
CS215
Lab2
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

int main()
{
  ifstream fin;
  int wordCount = 0, vowelCount = 0, consonantCount = 0, digitCount = 0, specialCharCount = 0;
  int vowelTotal = 0, consonantTotal = 0, digitTotal = 0, specialCharTotal = 0;
  
  fin.open("words.txt");
  string word = "";

  cout << setw(8) << "Word" << setw(8) << "Vowels" << setw(8) << "Const." << setw(8) << "Digits" << setw(8) << "Special" << endl;
  
  while (fin >> word) 
    {
      wordCount++;
      for (int i = 0; i < word.length(); i++) 
	{
	  if (isalpha(word[i])) 
	    {
	      if (word[i] == 'A' || word[i] == 'a' || word[i] == 'E' || word[i] == 'e' || word[i] == 'I' || word[i] == 'i' || word[i] == 'O' || word[i] == 'o' || word[i] == 'U' || word[i] == 'u')
		vowelCount++;
	      else 
		consonantCount++;
	    }
	    else 
	      {
		if (isdigit(word[i]))
		  digitCount++;
		else 
		  specialCharCount++;
	      }
	}
      cout << setw(8) << wordCount << setw(8) << vowelCount << setw(8) << consonantCount << setw(8) << digitCount << setw(8) << specialCharCount << endl;
      vowelTotal += vowelCount;
      consonantTotal += consonantCount;
      digitTotal += digitCount;
      specialCharTotal += specialCharCount;
      vowelCount = 0, consonantCount = 0, digitCount = 0, specialCharCount = 0;
    }
  fin.close();
  cout << setw(8) << "" << setw(8) << "---" << setw(8) << "---" << setw(8) << "---" << setw(8) << "---" << endl;
  cout << setw(8) << "Totals" << setw(8) << vowelTotal << setw(8) << consonantTotal << setw(8) << digitTotal << setw(8) << specialCharTotal << endl;

  return 0;
}
	 
