/*
primeTable.cpp
Eric Brewer
10/21/10
Ledin
CS454 - Theory of Computation
Primes Table -
*/

#include <iostream>
using namespace std;
#include <iomanip>
#include <math.h>

#define TABLE_BOUND 700
#define _DISPLAY 41

float quadratic1( int a, int b, int c );
float quadratic2( int a, int b, int c );

int table[TABLE_BOUND][TABLE_BOUND];

int main(){

  cout << "\nCurrently using a height and width of: " << TABLE_BOUND << "\n";

  table[0][0] = 4;
  for( int i = 1; i < TABLE_BOUND; i++ ){
    table[0][i] = table[0][i-1] + 3;
  }
  for( int j = 0; j < TABLE_BOUND; j++ ){
    for( int k = 1; k < TABLE_BOUND; k++ ){
      table[k][j] = table[k-1][j] + (2 * j + 3);
    }
  }

  cout << "Displaying only " << _DISPLAY << " rows and columns of the table.\n\n";
  for( int i = 0; i < _DISPLAY; i++ ){
    for( int j = 0; j < _DISPLAY; j++ )
      cout << setw(5) << right << table[i][j];
    cout << setw(5) << right << "...\n";
  }
  for( int i = 0; i < _DISPLAY; i++ )
    cout << setw(5) << right << "...";
      
  cout << "\n\nThe largest number in the table is: " << table[TABLE_BOUND-1][TABLE_BOUND-1] << ".\n";
  cout << "The number in the top-right corner is " << table[0][TABLE_BOUND-1] << ".\n";

  int pinput = 1;
  int a = 2;
  int b = 2;
  int c = 0;
  int row = 0;
  int col = 0;
  int q1 = 0;
  int q2 = 0;
  float f1 = 0.0;
  float f2 = 0.0;
  bool found = false;
  bool good = true;

  while( true ){
    cout << "\nCheck for primality (0 to quit): ";
    cin >> pinput;

    if( cin.fail() ){
      cout << "Bad input, exiting.\n";
      return 0;
    }
      
    good = true;
    if( !pinput )
      return 0;
    if( pinput > ( 2 * table[TABLE_BOUND-1][TABLE_BOUND-1] + 1 ) ){
      cout << "Try using a number smaller than " << ( 2 * table[TABLE_BOUND-1][TABLE_BOUND-1] + 1 ) << "\n";
      good = false;
    } 
    if( pinput > 2 && !(pinput % 2) )
      found = true;
    else{
      c = (pinput - 1) / 2;
      found = false;
      for( row = 0; !found && row < TABLE_BOUND; row++ )
	for( col = 0; !found && col < TABLE_BOUND; col++ )
	  if( table[row][col] == c )
	    found = true;

      /*
      c = (pinput - 1) / 2;
      f1 = quadratic1( a, b, (-1 * c) );
      f2 = quadratic2( a, b, (-1 * c) );
      q1 = f1;
      q2 = f2;
      cout << q1 << '\t' << q2 << "\n";
      cout << f1 << '\t' << f2 << "\n";
      found = ( q1 == f1 || q2 == f2 );      
      */
    }

    if( good )
      if( found )
	cout << " Not prime.\n";
      else
	cout << "            Prime!\n";
  }

  return 0;
}

float quadratic1( int a, int b, int c ){
  return (float)( ( (float)-b + sqrt((float)(( b * b ) - (4 * a * c)))) / 2 * a );
}

float quadratic2( int a, int b, int c ){
  return (float)( ( (float)-b - sqrt((float)(( b * b ) - (4 * a * c)))) / 2 * a );
}
