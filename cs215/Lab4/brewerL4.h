/*
Eric Brewer
2/18/09
CS215
Lab4
*/


#ifndef WORDDATA
#define WORDDATA

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class WordData
{
 public:
  WordData ();
  WordData (const WordData & OtherWord);
  ~WordData ();
  void SetWord (const string & InWord);
  string GetWord () const;
  void WriteData (ostream & outs) const;

  private:
  char * word;          // C-string to hold the word
  int vowels;           // vowel counter
  int consonants;       // consonant counter
  int digits;           // digit counter
  int specialchars;     // special character counter
};

// Function implementations will be placed here
WordData::WordData()
{
  word = new char[1];
  word[0] = '\0';
  vowels = 0;
  consonants = 0;
  digits = 0;
  specialchars = 0;
}

WordData::WordData (const WordData & OtherWord)
{
  strcpy(word, OtherWord.word);
  vowels = OtherWord.vowels;
  consonants = OtherWord.consonants;
  digits = OtherWord.digits;
  specialchars = OtherWord.specialchars;
}

WordData::~WordData()
{
  delete[] word;
}

void WordData::SetWord(const string & InWord)
{
  delete[] word;
  word = new char[1 + InWord.length()];
  strcpy(word, InWord.c_str());
  
  for (int i = 0; i < strlen(word); i++)
    {
      char c = tolower(word[i]);
      if (isalpha(c))
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	  vowels++;
	else
	  consonants++;
      else
	if (isdigit(c))
	  digits++;
	else
	  specialchars++;
    }
}
string WordData::GetWord() const
{
  return word;
}

void WordData::WriteData(ostream & outs) const
{
  outs << setw(12) << left << word 
       << setw(8) << right << vowels 
       << setw(8) << right << consonants
       << setw(8) << right << digits
       << setw(8) << right << specialchars;
}


#endif
