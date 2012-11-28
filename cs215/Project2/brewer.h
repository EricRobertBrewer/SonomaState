/*
Eric Brewer
3/10/09
CS215
Project2
Header file for the polynomial class.
*/

#ifndef POLYNOMIAL
#define POLYNOMIAL

/*
#include"polynomial.h"

#include<iostream>
using namespace std;
*/

class polynomial
{
 public:
  polynomial();
  polynomial(const polynomial & other);
  polynomial(int D);
  polynomial(int D, int * C);
  ~polynomial();
  polynomial & operator = (const polynomial & other);
  polynomial operator + (const polynomial & other) const;
  polynomial operator - (const polynomial & other) const;
  polynomial operator * (const polynomial & other) const;
  //polynomial operator / (const polynomial & other) const;                                                                                                                                                   
  friend istream & operator >> (istream & ins, polynomial & P);                                                                                                                                              
  friend ostream & operator << (ostream & outs, const polynomial & P);

 private:
  int d;
  int * c;
};

#endif
