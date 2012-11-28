/*
Eric Brewer
3/4/09
CS215
Lab6
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
  //void SetWord (const string & InWord);
  string GetWord () const;
  //void WriteData (ostream & outs) const;
  int GetNumVowels () const;
  int GetNumConsonants () const;
  int GetNumDigits () const;
  int GetNumSpecialChars () const;
  WordData & operator = (const WordData & OtherWord);
  bool operator == (const WordData & OtherWord) const;
  WordData operator + (const WordData & OtherWord) const;
  friend istream & operator >> (istream & ins, WordData & wd);
  friend ostream & operator << (ostream & outs, const WordData & w);

 private:
  char * word;        // C-string to hold the word
  int vowels;         // vowel counter 
  int consonants;     // consonant counter 
  int digits;         // digit counter 
  int specialchars;   // special character counter
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
  word = new char[1 + strlen(OtherWord.word)];
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

/*
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
*/

string WordData::GetWord() const
{
  return word;
}

/*
void WordData::WriteData(ostream & outs) const
{
  outs << setw(12) << left << word
       << setw(8) << right << vowels
       << setw(8) << right << consonants
       << setw(8) << right << digits
       << setw(8) << right << specialchars;
}
*/

int WordData::GetNumVowels () const
{
  return vowels;
}

int WordData::GetNumConsonants () const
{
  return consonants;
}

int WordData::GetNumDigits () const
{
  return digits;
}

int WordData::GetNumSpecialChars () const
{
  return specialchars;
}

WordData & WordData::operator = (const WordData & OtherWord)
{
  if (strcmp(word, OtherWord.word) != 0)
    {
      delete [] word;
      word = new char[1 + strlen(OtherWord.word)];
      strcpy(word, OtherWord.word);
      vowels = OtherWord.vowels;
      consonants = OtherWord.consonants;
      digits = OtherWord.digits;
      specialchars = OtherWord.specialchars;
    }
  return *this;
}
  
bool WordData::operator == (const WordData & OtherWord) const
{
  if (this == &OtherWord)
    {
      return true;
    }
  if (strcmp(word, OtherWord.word) == 0)
    {
      return true;
    }
  return false;
}

WordData WordData::operator + (const WordData & OtherWord) const
{
  WordData W1;
  W1 = *this;
  strcpy(W1.word, strcat(W1.word, OtherWord.word));  
  W1.vowels += OtherWord.vowels;
  W1.consonants += OtherWord.consonants;
  W1.digits += OtherWord.digits;
  W1.specialchars += OtherWord.specialchars;
  return W1;
}

istream & operator >> (istream & ins, WordData & wd)
{
  string tempstr;
  ins >> tempstr;
  if (!ins.fail())
    {
      delete[] wd.word;
      wd.word = new char[1 + tempstr.length()];
      strcpy(wd.word, tempstr.c_str());

      wd.vowels = 0;
      wd.consonants = 0;
      wd.digits = 0;
      wd.specialchars = 0;

      for (int i = 0; i < strlen(wd.word); i++)
	{
	  char c = tolower(wd.word[i]);
	  if (isalpha(c))
	    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	      wd.vowels++;
	    else
	      wd.consonants++;
	  else
	    if (isdigit(c))
	      wd.digits++;
	    else
	      wd.specialchars++;
	}
    }
  return ins;
}

ostream & operator << (ostream & outs, const WordData & w)
{
  outs << left << setw(12) << w.word
       << right << setw(8) << w.vowels
       << right << setw(8) << w.consonants
       << right << setw(8) << w.digits
       << right << setw(8) << w.specialchars;
  return outs;
}

#endif

