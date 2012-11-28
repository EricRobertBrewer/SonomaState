/*
Eric Brewer
5/14/09
CS215
Project5 - Calculator
  Keeping order of operations in mind, this program
  evaluates mathematical expressions. You must give
  the program flawless input. Uses recursive calls to
  deal with parentheses. Checks for order of 
  operations such as (4 - 4 - 5) = -5 or (3 + 2 * 5)
  = 13. Can only evaluate expressions that begin with
  single digits.
*/

#include<iostream>
using namespace std;
#include<vector>
//Used for stacking numbers and operators

int Evaluate(const vector<char> & v, int & index);
int operation(int n1, char oprtr, int n2);
int evalStart = 0;
bool mult = false;

vector<int> numStack;
vector<char> oprStack;

int main()
{
  vector<char> fullExpr;
  string inString;

  cin >> inString;
  for (int i = 0; i < inString.length(); ++i)
    fullExpr.push_back(inString[i]);
  
  int sol = Evaluate(fullExpr, evalStart); 
  cout << sol << endl;

  return 0;
}
//Takes only one expression per execution of the program. 
// Waiting for more input until the user hits 'q' for 
// example, caused a lot of problems.

int Evaluate(const vector<char> & v, int & index)
{  
  if(v[index] == '(')
    numStack.push_back(Evaluate(v, ++index));
  else
    numStack.push_back(v[index] - '0');
  ++index;
  
  oprStack.push_back(v[index]);
  ++index;

  while(v[index] != ')' && index <= v.size()-1)
    {
      if (!mult)
	{
	  if(v[index] == '(')
	    numStack.push_back(Evaluate(v, ++index));
	  else
	    numStack.push_back(v[index] - '0');
	  ++index;
	}
      mult = false;
      
      if(v[index] == ')' || index == v.size());
      else
	{
	  if((v[index] == '*' || v[index] == '/') && !oprStack.empty() &&
	     (oprStack.back() == '+' || oprStack.back() == '-'))
	    {
	      oprStack.push_back(v[index]);
	      ++index;
	      if(v[index] == '(')
		numStack.push_back(Evaluate(v, ++index));
	      else
		numStack.push_back(v[index] - '0');
	      ++index;
	      int temp = operation(numStack[numStack.size()-2],
				   oprStack.back(),
				   numStack.back());
	      numStack.pop_back();
	      oprStack.pop_back();
	      numStack.pop_back();
	      numStack.push_back(temp);
	      mult = true;
	    }
	  else
	    {
	      int temp = operation(numStack[numStack.size()-2],
				   oprStack.back(),
				   numStack.back());
	      numStack.pop_back();
	      oprStack.pop_back();
	      numStack.pop_back();
	      numStack.push_back(temp);
	      oprStack.push_back(v[index]);
	      ++index;
	    }
	}
    }

  int temp = operation(numStack[numStack.size()-2],
		       oprStack.back(),
		       numStack.back());
  numStack.pop_back();
  oprStack.pop_back();
  numStack.pop_back();
  return temp;
}
  
int operation(int n1, char oprtr, int n2)
{
  int a = 0;
  
  if(oprtr == '+')
    a = n1 + n2;
  else if(oprtr == '-')
    a = n1 - n2;
  else if(oprtr == '*')
    a = n1 * n2;
  else if(oprtr == '/')
    a = n1 / n2;

  return a;
}
//Super generic calculator function.
