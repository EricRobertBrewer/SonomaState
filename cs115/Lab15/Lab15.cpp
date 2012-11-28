/*
Eric Brewer
12/9/08
Rivoire
Lab 15
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "word.h"
using namespace std;
int main ()
{
  ifstream input ("lab15.in");
  vector<Word> sentence;
  Word one;
  while (input >> one)
    sentence.push_back(one);
  int count = sentence.size();;
  reverse(sentence.begin(), sentence.end());
  cout << "Unsorted list:\n";
  for (int i = 0; i < count; i++)
    cout << '\t' << sentence[i] << endl;
  sort (sentence.begin(), sentence.end());
  cout << "Sorted list:\n";
  for (int i = 0; i < count; i++)
    cout << '\t' << sentence[i] << endl;
  Word all;
  for (int i = 0; i < count; i++)
    all = all + sentence[i];
  cout << "All of the words: " << all << endl;
  sentence.clear();
  cout << "Final sentence length: " << sentence.size() << endl;
  return 0;
}
