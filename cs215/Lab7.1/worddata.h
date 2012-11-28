/*
Eric Brewer
3/11/09
CS215
Lab7
*/

#ifndef WORDDATA
#define WORDDATA

#include<string>
#include<iostream>
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
  bool operator > (const WordData & OtherWord) const;
  WordData operator + (const WordData & OtherWord) const;
  friend istream & operator >> (istream & ins, WordData & w);
  friend ostream & operator << (ostream & outs, const WordData & w);

 private:
  char * word;
  // C-string to hold the word                                                                                              
  int vowels;
  // vowel counter                                                                                                           
  int consonants;
  // consonant counter                                                                                                     
  int digits;
  // digit counter                                                                                             
  int specialchars;
  // special character counter                                                                                              
};

#endif
