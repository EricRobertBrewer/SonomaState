/*
Eric Brewer
2/11/09
CS215
Lab3
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<cstring>

using namespace std;

const int MAX_WORDS = 100;

struct worddata
{
  char * word;
  int vowels;
  int consonants;
  int digits;
  int specialChars;
};

void SelSort(worddata words[], const int &index);
void Swap(worddata &a, worddata &b);

int main()
{
  ifstream fin;
  int wordCount = 0; 
  //int vowelCount = 0, consonantCount = 0, digitCount = 0, specialCharCount = 0;
  int vowelTotal = 0, consonantTotal = 0, digitTotal = 0, specialCharTotal = 0;

  worddata wordSet[MAX_WORDS];
  char buffer[1000];

  fin.open("words.txt");
  //string word = "";

  int count = 0;

  while (fin >> buffer)
    {
      wordSet[count].word = new char[strlen(buffer) + 1];
      strcpy(wordSet[count].word, buffer);
      wordSet[count].vowels = 0;
      wordSet[count].consonants = 0;
      wordSet[count].digits = 0;
      wordSet[count].specialChars = 0;


      for (int i = 0; i < strlen(wordSet[count].word); i++)
	{
	  char c = wordSet[count].word[i];
	  if (isalpha(c))
	    {
	      if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u')
		wordSet[count].vowels++;
	      else
		wordSet[count].consonants++;
	    }
	  else
	    {
	      if (isdigit(c))
		wordSet[count].digits++;
	      else
		wordSet[count].specialChars++;
	    }
	}
    
      vowelTotal += wordSet[count].vowels;
      consonantTotal += wordSet[count].consonants;
      digitTotal += wordSet[count].digits;
      specialCharTotal += wordSet[count].specialChars;
      //vowelCount = 0, consonantCount = 0, digitCount = 0, specialCharCount = 0;
      wordCount++;
      count++;
    }
  
  fin.close();

  SelSort(wordSet, count);
  
  cout << setw(16) << left << "Word" << setw(8) << "Vowels" << setw(8) << "Const." << setw(8) << "Digits" << setw(8) << "Special" << endl;
  for(int j = 0; j < wordCount; j++)
    { 
      cout << setw(16) << left << wordSet[j].word << setw(8) << wordSet[j].vowels << setw(8) << wordSet[j].consonants << setw(8) << wordSet[j].digits << setw(8) << wordSet[j].specialChars << endl;
    }
  cout << setw(16) << left << "" << setw(8) << "---" << setw(8) << "---" << setw(8) << "---" << setw(8) << "---" << endl;
  cout << setw(16) << left << "Totals" << setw(8) << vowelTotal << setw(8) << consonantTotal << setw(8) << digitTotal << setw(8) << specialCharTotal << endl;

  return 0;
}

void SelSort(worddata words[], const int &index)
{
  char smallest [1000];
  int smallIndex = 0;
  
  for(int x = 0; x < (index - 1); x++)
    {
      strcpy(smallest, words[x].word);
      for(int y = x; y < index; y++)
	{
	  if (strcmp(smallest, words[y].word) > 0)
	    {
	      smallIndex = y;
	      strcpy(smallest, words[y].word);
	    }
	}
      Swap(words[smallIndex], words[x]);
    }    
}

void Swap(worddata &a, worddata &b)
{
  worddata temp;
  temp = a;
  a = b;
  b = temp;
}
