#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <cstring>
using namespace std;
class Word {
 public:
  Word ();                   // Default constructor
  Word (const Word& other); // Copy constructor
  ~Word ();                  // Destructor
  Word& operator = (const Word& other);    // Assignment operator
  bool operator > (const Word& other) const; // Comparison op.
  Word operator + (const Word& other) const; // Addition operator
  // Input and output operators
  friend istream& operator >> (istream& ins, Word& w);
  friend ostream& operator << (ostream& outs, const Word& w);
 private:
  int length;
  char * data;
};
// Default constructor
Word::Word () {
  this->length = 0;
  this->data = new char [1];
  this->data[0] = '\0';
}
// Copy constructor
Word::Word (const Word& other) {
  this->length = other.length;
  this->data = new char [this->length + 1];
  strcpy (this->data, other.data);
}
// Destructor
Word::~Word () {
  delete [] this->data;
}
// Assignment operator
Word& Word::operator = (const Word& other) {
  if (this == &other) {
    return *this;
  }
  if (this->length != other.length) {
    delete [] this->data;
    this->length = other.length;
    this->data = new char [this->length + 1];
  }
  strcpy (this->data, other.data);
  return *this;
}
// Comparison operator
  bool Word::operator > (const Word& other) const {
    if (this->length != other.length) {
      return (this->length > other.length);
    }
    if (strcmp (this->data, other.data) < 0) {
      return true;
    }
    return false;
  }
// Addition operator
Word Word::operator + (const Word& other) const {
  Word temp;
  temp.length = this->length + other.length;
  temp.data = new char [temp.length + 1];
  strcpy (temp.data, this->data);
  strcat (temp.data, other.data);
  return temp;
}
// Input operator
istream& operator >> (istream& ins, Word& w) {
  char buffer[256];
  ins >> buffer;
  if (ins.fail()) {
    return ins;
  }
  delete [] w.data;
  w.length = strlen(buffer);
  w.data = new char [w.length + 1];
  strcpy (w.data, buffer);
  return ins;
}
// Output operator
ostream& operator << (ostream& outs, const Word& w) {
  outs << w.data;
  return outs;
}
#endif
