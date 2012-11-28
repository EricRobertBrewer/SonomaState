/*
Eric Brewer
3/10/09
CS215
Project2
This class stores a polynomial using just two
variables - a degree stored in an integer and an
array of coefficients also stored as integers.
Implements various constructors, destructor, addition,
subtraction, multiplication, input and output of such
polynomials.
*/


/*
#ifndef POLYNOMIAL
#define POLYNOMIAL

#include<iostream>
using namespace std;

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
  //friend istream & operator >> (istream & ins, polynomial & P);
  friend ostream & operator << (ostream & outs, const polynomial & P);

 private:
  int d;
  int * c;
};
*/

#include<fstream>
#include<iostream>
using namespace std;

#include "polynomial.h"

polynomial :: polynomial()
{
  d = 0;
  //delete [] c;
  c = new int[1];
  c[0] = 0;
}

polynomial :: polynomial(const polynomial & other)
{
  d = other.d;
  //delete[ ] c;
  c = new int[d+1];
  for (int i = 0; i < (d+1); i++)
    c[i] = other.c[i];
}

polynomial :: polynomial(int D)
{
  if (D > -1)
    {
      d = D;
      //delete [] c;
      c = new int[d+1];
      for (int i = 0; i < (d+1); i++)
	c[i] = 0;
    }
}

polynomial :: polynomial(int D, int * C)
{
  if (D > -1)
    {
      d = D;
      //delete [] c;
      c = new int[d+1];
      for (int i = 0; i < (d+1); i++)
	c[d-i] = C[i];
    }
}

polynomial :: ~polynomial()
{
  delete [] c;
}

polynomial & polynomial :: operator = (const polynomial & other)
{
  if (&other != this)
    {
      d = other.d;
      delete [] c;
      c = new int[d+1];
      for (int i = 0; i < (d+1); i++)
	c[i] = other.c[i];
    }

  return *this;
}

polynomial polynomial :: operator + (const polynomial & other) const
{
  polynomial temp;

  if (d > other.d)
    {
      temp.d = d;
      for (int i = 0; i < (other.d+1); i++)
	temp.c[i] = (c[i] + other.c[i]);
      for (int i = (other.d+1); i < (d+1); i++)
	temp.c[i] = c[i];
    }
  else
    {
      temp.d = other.d;
      for (int i = 0; i < (d+1); i++)
	temp.c[i] = (c[i] + other.c[i]);
      for (int i = (d+1); i < (other.d+1); i++)
	temp.c[i] = other.c[i];
    }

  return temp;
}

polynomial polynomial :: operator - (const polynomial & other) const
{
  polynomial temp;

  if (d > other.d)
    {
      temp.d = d;
      for (int i = 0; i < (other.d+1); i++)
	temp.c[i] = (c[i] - other.c[i]);
      for (int i = (other.d+1); i < (d+1); i++)
	temp.c[i] = c[i];
    }
  else
    {
      temp.d = other.d;
      for (int i = 0; i < (d+1); i++)
        temp.c[i] = (c[i] - other.c[i]);
      for (int i = (d+1); i < (other.d+1); i++)
        temp.c[i] = (0 - other.c[i]);
    }

  return temp;
}

polynomial polynomial :: operator * (const polynomial & other) const
{
  polynomial floor(d + other.d);
  
  for (int i = 0; i < (d+1); i++)
    {
      //polynomial story(other.d + 1 + i);

      for (int j = 0; j < (other.d+1); j++)
	floor.c[j + i] = (floor.c[j + i] + (other.c[j] * c[i]));
      
      //floor = (story + floor);
    }

  return floor;
}

/*
polynomial polynomial :: operator / (const polynomial & other) const
{
}
*/


istream & operator >> (istream & ins, polynomial & P)
{
  char a;
  int t1 = 0;
  int t2 = 0;
  bool door = false;

  a = ins.peek();
  if (isdigit(a) || a == '+' || a == '-')
    {
      ins >> t1;
      a = ins.peek();
      if (a == 'x')
	{
	  ins >> a;
	  a = ins.peek();
	  if (a == '^')
	    {
	      ins >> a;
	      ins >> t2;
	      delete [] P.c; 
	      P.c = new int[t2+1];
	      P.c[t2] = t1;
	    }
	  if (a == '+' || a == '-')
	    {
	      delete [] P.c;
	      P.c = new int[2];
	      P.c[1] = t1;
	    }
	  if (ins.eof())
	    {
	      delete [] P.c;
	      P.c = new int[2];
	      P.c[1] = t1;
	      door = true;
	    }
	}
      if (ins.eof())
	{
	  P.c[0] = t1;
	  door = true;
	}
    }
  if (a == 'x')
    {
      t1 = 1;
      a = ins.peek();
      if (a == '^')
	{
	  ins >> a;
	  ins >> t2;
	  delete [] P.c;
	  P.c = new int[t2+1];
	  P.c[t2] = t1;
	}
      if (a == '+' || a == '-')
	{
	  delete [] P.c;
	  P.c = new int [2];
	  P.c[1] = t1;
	}
      if (ins.eof())
	{
	  delete [] P.c;
	  P.c = new int[2];
	  P.c[1] = t1;
	  door = true;
	}
    }
  
  while (!door)
    {
      a = ins.peek();
      if (isdigit(a) || a == '+' || a == '-')
	{
	  ins >> t1;
	  a = ins.peek();
	  if (a == 'x')
	    {
	      ins >> a;
	      a = ins.peek();
	      if (a == '^')
		{
		  ins >> a;
		  ins >> t2;
		  P.c[t2] = t1;
		}
	      if (a == '+' || a == '-')
		{
		  P.c[1] = t1;
		}
	      if (ins.eof())
		{
		  P.c[1] = t1;
		  door = true;
		}
	    }
	  if (ins.eof())
	    {
	      P.c[0] = t1;
	      door = true;
	    }
	}
      if (ins.eof())
	{
	  for (int k = 0; k < t2; k++)
	    P.c[k] = 0;
	  door = true;
	}
    }
	      
  return ins;
}

ostream & operator << (ostream & outs, const polynomial & P)
{
  bool print = false;
  
  if (P.d > 1)
    {
      for (int i = P.d; i > 1; i--)
	{
	  if (P.c[i] != 0)
	    {
	      if (P.c[i] > 0)
		{
		  if (print)
		    {
		      outs << '+';
		    }
		  if (P.c[i] != 1)
		    {
		      outs << P.c[i];
		    }
		  outs << "x^" << i;
		  print = true;
		}
	      else
		{
		  if (P.c[i] != -1)
		    {
		      outs << P.c[i];
		    }
		  else
		    {
		      outs << '-';
		    }
		  outs << "x^" << i;
		  print = true;
		}
	    }
	}
    }

  if (P.c[1] != 0)
    {
      if (P.c[1] > 0)
	{
	  if (print)
	    {
	      outs << '+';
	    }
	  if (P.c[1] != 1)
	    {
	      outs << P.c[1];
	    }
	  outs << 'x';
	  print = true;
	}
      else
	{
	  outs << P.c[1] << 'x';
	  print = true;
	}
    }

  if (P.c[0] != 0)
    {
      if (P.c[0] > 0)
	{
	  outs << '+' << P.c[0];
	  print = true;
	}
      else
	{
	  outs << P.c[0];
	  print = true;
	}
    }

  if (!print)
    outs << '0';
		
  return outs;
}
