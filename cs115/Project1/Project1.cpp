/*
Eric Brewer
9/23/08   
Rivoire - CS115 TuTh 2:30P; Tues. Lab
Project 1 - This program first asks for three 
 integers from the user. The program then 
 determines and outputs the arithmetic 
 mean of the three integers, the greatest
 integer, the least integer, and if the
 sequence of integers is a Pythagorean
 triple by means of basic programming 
 functions including if-else statements.
Lines - 149
*/


#include <iostream>
#include <iomanip> //For the 2-digit precision of the mean.
#include <cmath> //For calculating the Pythagorean triple (pow).
using namespace std;

int main()
{
  int inA, inB, inC, calcGreat, calcMid, calcLeast;   //The input variables and the results for
                                                      // greatest, middle, and least terms.
  float mean;   //The mean; must be a float.
  cout << "Enter 3 integers: " << endl;
  cin >> inA >> inB >> inC;

  if (cin.fail() == 0)
    {
      //Regardless of the values of the integers, the mean shall be calculated.
      mean = (inA + inB + inC) / 3.0;
      cout << fixed << setprecision(2);
      cout << "Mean = " << mean << endl;

      //If all three values are different...
      if (inA != inB && inA != inC && inB != inC)
	{   
	  //Simply finds the greatest value.
	  if (inA > inB && inA > inC)
	    calcGreat = inA;
	  else if (inB > inA && inB > inC)
	    calcGreat = inB;
	  else
	    calcGreat = inC;
	  cout << "Greatest = " << calcGreat << endl;

	  //Finds the least value.
	  if (inA < inB && inA < inC)
	    calcLeast = inA;
	  else if (inB < inA && inB < inC)
	    calcLeast = inB;
	  else calcLeast = inC;
	  cout << "Least = " << calcLeast << endl;

	  //Defines the middle value through process of elimination.
	  if (inA == calcGreat)
	    {
	      if (inB == calcLeast)
		calcMid = inC;
	      else
		calcMid = inB;
	    }
	  else if (inB == calcGreat)
	    {
	      if (inA == calcLeast)
		calcMid = inC;
	      else
		calcMid = inA;
	    }
	  else
	    {
	      if (inA == calcLeast)
		calcMid = inB;
	      else
		calcMid = inA;
	    }

	  //The Pythagorean calculations - must be positive integers
	  if (inA > 0 && inB > 0 && inC > 0)
	    {
	      //The reason why i needed the cmath library.
	      if ((pow(calcLeast, 2) + pow(calcMid, 2)) == pow(calcGreat, 2))   
		cout << "Pythagorean triple" << endl;
	      else
		cout << "Not a Pythagorean triple" << endl;
	    }
	  else
	    cout << "Not a Pythagorean triple" << endl;
	}

      //If all values are equal...
      else if (inA == inB && inA == inC)
	{
	  cout << "Greatest = " << inA << endl;
	  cout << "Least = " << inA << endl;
	  cout << "Not a Pythagorean triple" << endl;
	}

      //If exactly two values are equal...
      else if (inA == inB && inA != inC)
	{
	  if (inA > inC)
	    {
	      cout << "Greatest = " << inA << endl;
	      cout << "Least = " << inC << endl;
	    }
	  else
	    {
	      cout << "Greatest = " << inC << endl;
	      cout << "Least = " << inA << endl;
	    }
	  cout << "Not a Pythagorean triple" << endl;
	}
      else if (inA == inC && inA != inB)
	{
	  if (inA > inB)
	    {
	      cout << "Greatest = " << inA << endl;
	      cout << "Least = " << inB << endl;
	    }
	  else
	    {
	      cout << "Greatest = " << inB << endl;
	      cout << "Least = " << inA << endl;
	    }
	  cout << "Not a Pythagorean triple" << endl;
	}
      else
	{
	  if (inB > inA)
	    {
	      cout << "Greatest = " << inB << endl;
	      cout << "Least = " << inA << endl;
	    }
	  else
	    {
	      cout << "Greatest = " << inA << endl;
	      cout << "Least = " << inB << endl;
	    }
	  cout << "Not a Pythagorean triple" << endl;
	}
    }
  else
    cout << "Invalid input" << endl;

  return 0;
}
