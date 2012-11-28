// h.cpp
// Smart Brain is a Tasty Brain
// Stephen Gulland, Vinh Gruenhagen, Eric Brewer
#include<iostream>
#include<fstream>
using namespace std;
#define DEBUG 0
#define debug if (DEBUG) cout

char paren(char expr[], int &pos);
char orf( char one, char two);
char andf(char one, char two);

int main()
{
  debug << "starting Program" << endl;
  ifstream ins( "h.in" );
  int num = 0;
  ins >> num;
  char test[500];
  debug << "Cases are: " << num << endl;
  ins.getline( test, 55 );
  for(int i = 0; i < num; i++)
    {
      char answer;
      char expression[55];
      ins.getline( expression, 55 );
      debug << expression << endl;
      int pos = 0;
      if( expression[pos] == '!')
	{
	  pos++;
	  answer = paren( expression , pos);
	  if( answer == 't')
	    answer = 'f';
	  else
	    answer = 't';
	}
      else
	{
	  answer = paren( expression , pos);
	}
      debug << "answer is: " << answer << endl;
      pos += 3;
      debug << "brain said: " << expression[pos] << endl;
      if( answer == expression[pos] )
	cout << i+1 << ": Good brain" << endl;
      else
	cout << i+1 << ": Bad brain" << endl;
    }
  return 0;
}

char paren(char expr[], int &pos)
{
  debug << "Entering paren" << endl;
  pos++;
  char one,two,sign;
  if( expr[pos] == '!' )
    {
      pos++;
      if( expr[pos] == '(')
	{
	  one = paren(expr , pos);
	  debug << "Excla Recursive Paren One: " << one << " " << pos << endl;
	  if( one == 't')
	    one = 'f';
	  else
	    one = 't';
	}
      else
	{
	  one = expr[pos];
	  debug << "Excla Variable One: " << one << " " << pos << endl;
	  pos++;
	  if( one == 't' )
	    one = 'f';
	  else
	    one = 't';
	}
    }
  else if( expr[pos] == '(')
    {     one = paren(expr , pos);
      debug << "Recursive Paren One: " << one << " " << pos << endl;
    }
  else
    {
      one = expr[pos];
      debug << "Variable One: " << one << " " << pos << endl;
      pos++;
    }
  sign = expr[pos];
  pos++;
  debug << "Sign is: " << sign << " " << pos << endl;
  if( expr[pos] == '!' ) 
    {
      pos++;
      if( expr[pos] == '(')
	{
	  two = paren(expr , pos);
	  debug << "Excla Recursive Paren Two: " << two << " " << pos << endl;
	  if( two == 't')
	    two = 'f';
	  else
	    two = 't';
	}
      else
	{
	  two = expr[pos];
	  debug << "Excla Variable Two: " << two << " " << pos << endl;
	  pos++;
	  if( two == 't' )
	    two = 'f';
	  else
	    two = 't';
	}
    }
  else if(expr[pos] == '(')
    {
       two = paren(expr , pos);
       debug << "Recursive Paren Two: " << two << " " << pos << endl;
    }
  else
    {
      two = expr[pos];
      debug << "Variable Two: " << two << " " << pos << endl;
      pos++;
    }
  pos++;
  if( sign == '|')
    {
      char temp = orf(one , two);
      debug << "Paren or: " << temp << endl;
      return temp;
    }
  else
    {
      char temp = andf(one, two);
      debug << "Paren and: " << temp << endl;
      return temp;
    }
}

char orf(char one, char two)
{
  if( (one == 't') || (two == 't') )
    return 't';
  return 'f';
}

char andf(char one, char two)
{
  if( (one == 't') && (two == 't'))
    return 't';
  return 'f';
}
