/*
binomial.h
Eric Brewer
2/17/09
CS215
Project1 - Binomial type:
 Stores two integers together as a
 binomial in the form (c1)x + (c2).
 Also includes basic functions such
 as initialization, input and output
 calling, and addition and subtraction.
*/

#include<iostream>

using namespace std;

struct binomial 
{
  int c1;
  int c2;
};

  void init(binomial & B)
  {
    B.c1 = 0;
    B.c2 = 0;
  }
  
  void init(binomial & B, int C1, int C2)
  {
    B.c1 = C1;
    B.c2 = C2;
  }

  void input(istream & ins, binomial & B)
  {
    char x;
    char p;
    ins >> B.c1;
    if (!ins.fail())
      {
	ins >> x >> p;
	if (x == 'x' && p == '+')
	  {
	    ins >> B.c2;
	  }
      }
  }

  void output(ostream & outs, const binomial & B)
  {
    outs << B.c1 << 'x' << '+' << B.c2 << endl;
  }

  binomial sum(const binomial & B1, const binomial & B2)
  {
    binomial B;
    B.c1 = (B1.c1 + B2.c1);
    B.c2 = (B1.c2 + B2.c2);

    return B;
  }

  binomial difference(const binomial & B1, const binomial & B2)
  {
    binomial B;
    B.c1 = (B1.c1 - B2.c1);
    B.c2 = (B1.c2 - B2.c2);

    return B;
  }

