/*
Eric Brewer
1/28/08
CS215
Lab1
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin;
  
  int consonantCount = 0;
  int vowelCount = 0;
  int wordCount = 0;
  int digitCount = 0;
  int specialCharCount = 0;

  fin.open("words.txt");
  string word;
  while (fin >> word) {
    wordCount++;
    for (int i = 0; i < word.length(); i++) {
      if (isalpha(word[i])) {
	if (word[i] == 'A' || word[i] =='a' || word[i] =='E' || word[i] =='e' || word[i] =='I' || word[i] =='i' || word[i] =='O' || word[i] =='o' || word[i] =='U' || word[i] =='u') 
	  vowelCount++;
	else 
	  consonantCount++;
      }
      else {
	if (isdigit(word[i]))
	  digitCount++;
	else
	  specialCharCount++;
      }
    }
  }

  fin.close();

  cout << "Words: " << wordCount << "\n"
       << "Vowels: " << vowelCount << "\n"
       << "Consonants: " << consonantCount << "\n"
       << "Digits: " << digitCount << "\n"
       << "Special Characters: " << specialCharCount << "\n";
  
  
  return 0;
}
	  
