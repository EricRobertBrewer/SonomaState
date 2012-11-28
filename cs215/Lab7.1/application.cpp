/*
Eric Brewer
3/11/09
CS215
Lab7
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include"worddata.h"
#include"sorts.h"

using namespace std;

int main()
{
  int size = 20;
  int used = 0;
  ifstream fin;
  fin.open("Lab7.txt");

  WordData * book;
  book = new WordData[size];
  
  while (fin >> book)
    {
      fin >> book[used];
      used++;
      if (used==size)
	{
	  book = new WordData[10];
	  size += 10;
	}
    }

  fin.close();
  eSort(book, used);
  cout << setw(12) << left << "Word"
       << setw(8) << right << "Vowels"
       << setw(8) << right << "Consonants"
       << setw(8) << right << "Digits"
       << setw(8) << right << "SpecialChars" << endl;
  cout << book << endl << endl;
  iSort(book, used);
  cout << setw(12) << left << "Word"
       << setw(8) << right << "Vowels"
       << setw(8) << right << "Consonants"
       << setw(8) << right << "Digits"
       << setw(8) << right << "SpecialChars" << endl;
  cout << book << endl << endl;
  sSort(book, used);
  cout << setw(12) << left << "Word"
       << setw(8) << right << "Vowels"
       << setw(8) << right << "Consonants"
       << setw(8) << right << "Digits"
       << setw(8) << right << "SpecialChars" << endl;
  cout << book << endl << endl;

  return 0;
}
