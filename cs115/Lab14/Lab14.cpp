/*
Eric Brewer
12/2/08
Rivoire
Lab 14
*/

#include <iostream>
#include <fstream>
#include "word.h"
using namespace std;
const int MAXWORDS = 10;
void sort (Word words[], int numwords);
void swap (Word& w1, Word& w2);
int main () {
  ifstream input ("lab14.in");
  Word sentence [MAXWORDS];
  int count = 0;
  /* Input each word using the ">>" operator defined in the Word
     class */
  while (count < MAXWORDS && input >> sentence[count]) {
    count++;
  }
  /* Print out the list in the order it was read using the "<<"
     operator */
  cout << "Unsorted list:\n";
  for (int i = 0; i < count; i++) {
    cout << '\t' << sentence[i] << endl;
  }
  // Sort the list in the order defined by the ">" operator
  sort (sentence, count);
  // Print the sorted list
  cout << "Sorted list:\n";
  for (int i = 0; i < count; i++) {
    cout << '\t' << sentence[i] << endl;
  }
  // Use the "+" operator to concatenate the words
  Word all;
  for (int i = 0; i < count; i++) {
    all = all + sentence[i];
  }
  cout << "All of the words: " << all << endl;
  return 0;
}
void sort (Word words[], int numwords) {
  bool sorted = false;
  int i = 0;
  while ((i < numwords) && (sorted == false)) {
    sorted = true;
    for (int j = 1; j < numwords - i; j++) {
      if (words[j-1] > words[j]) {
	sorted = false;
	swap (words[j-1], words[j]);
      }
    }
    i++;
  }
}
void swap (Word & w1, Word & w2) {
  Word t = w1;
  w1 = w2;
  w2 = t;
}
