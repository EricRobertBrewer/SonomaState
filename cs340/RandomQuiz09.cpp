/*
RandomQuiz09.cpp
Eric Brewer
4/16/12
Ledin
CS340 - Computer Security and Malware
Random Quiz 09 - ECC calculations - 
  Elliptic Curve Point Addition Algorithm:
    y^2 = a*x^3 + b*x + c
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

#define DEBUG 0
#define debug if( DEBUG ) cout

#define ALPHABET 26
#define ENOUGH 250
#define SPACING 3

long long gcd( long long a, long long b );

int main( int argc, char* argv[] ){

  if( argc != 2 ){
    cout << "Error: 2 arguments needed: $ " << argv[0] << " <filename>\n";
    exit( 1 );
  }
  ifstream fin( argv[1] );
  if( fin.fail() ){
    cout << "Couldn't find file \"" << argv[1] << "\"\n";
    exit( 2 );
  }

  ofstream fout( "RandomQuiz09.results" );
  long long a, b, c;                      // Coefficients in ECC
  int n;                                  // Number of point pairs
  int i, j, k;                            // indices
  long long *xn = new long long[ENOUGH];  // x-value numerators
  long long *xd = new long long[ENOUGH];  // x-value denominators
  long long *yn = new long long[ENOUGH];  // y-value numerators
  long long *yd = new long long[ENOUGH];  // y-value denominators
  int s;                                  // Buffer index
  long long ln, ld;                       // Lambda numerator and denominator
  long long l;                            // Lowest common denominator
  long long axn, axd, ayn, ayd;           // x-result, y-result
  int m[ALPHABET][ALPHABET];              // Matrix of two-point sums (with doubles)
  bool found;                             // iteration flag
  int t[ALPHABET];                        // Matrix of point triples

  // Read stuff in from input file
  fin >> a >> b >> c;
  fin >> n;
  if( n > ALPHABET ){
    cout << "Error: array size too small OR 'n' too high\n";
    exit( 3 );
  }
  for( i = 0; i < n; i++ ){
    fin >> xn[i];
    fin >> yn[i];    
  }
  for( i = 0; i < n; i++ ){
    xd[i] = 1;
    yd[i] = 1;
  }
  s = n;

  // Add non-identical points
  for( i = 1; i < n; i++ )
    for( j = 0; j < i; j++ ){

      // x1 != x2
      if( xn[i] == xn[j] ){
	m[i][j] = -1;
	continue;
      }

      debug << "DEBUG: Checking valid non-identical points: [" << (char)( 'A' + i ) << "] + [" << (char)( 'A' + j ) << "]\n";

      // Lambda calculation
      ln = ( yn[j] * yd[i] - yn[i] * yd[j] ) * xd[j] * xd[i];
      ld = ( xn[j] * xd[i] - xn[i] * xd[j] ) * yd[j] * yd[i];
      // x-values
      axn = ( ln * ln * xd[i] - xn[i] * ld * ld ) * xd[j] - xn[j] * ld * ld * xd[i];
      axd = ld * ld * xd[i] * xd[j];
      l = gcd( axn, axd );
      debug << "LCD: " << l << endl;
      axn /= l;
      axd /= l;
      axn = ( axd < 0 ? -axn : axn );
      axd = ( axd < 0 ? -axd : axd );
      // y-values
      ayn = ln * ( xn[i] * axd - axn * xd[i] ) * yd[i] - yn[i] * ld * xd[i] * axd;
      ayd = ld * xd[i] * axd * yd[i];
      l = gcd( ayn, ayd );
      debug << "LCD: " << l << endl;
      ayn /= l;
      ayd /= l;
      ayn = ( ayd < 0 ? -ayn : ayn );
      ayd = ( ayd < 0 ? -ayd : ayd );

      // Search for existing point
      found = false;
      for( k = 0; k < s && !found; k++ )
	if( axn == xn[k] && axd == xd[k] && ayn == yn[k] && ayd == yd[k] ){
	  m[i][j] = k;
	  found = true;
	}
      if( !found ){
	m[i][j] = s;
	xn[s] = axn;
	xd[s] = axd;
	yn[s] = ayn;
	yd[s] = ayd;
	s++;
      }
    }
  for( i = 1; i < n; i++ )
    for( j = 0; j < i; j++ )
      m[j][i] = m[i][j];

  // points doubled
  for( i = 0; i < n; i++ ){

    // y1 != 0
    if( !yn[i] ){
      m[i][i] = -1;
      continue;
    }

    debug << "DEBUG: Checking valid points doubled: [" << (char)( 'A' + i ) << "]\n";

    // Lambda calculation
    ln = ( 3 * xn[i] * xn[i] + b * xd[i] * xd[i] ) * yd[i];
    ld = xd[i] * xd[i] * 2 * yn[i];
    // x-values
    axn = ln * ln * xd[i] - 2 * xn[i] * ld * ld;
    axd = ld * ld * xd[i];
    l = gcd( axn, axd );
    debug << "LCD: " << l << endl;
    axn /= l;
    axd /= l;
    axn = ( axd < 0 ? -axn : axn );
    axd = ( axd < 0 ? -axd : axd );
    // y-values
    ayn = ln * ( xn[i] * axd - axn * xd[i] ) * yd[i] - yn[i] * ld * xd[i] * axd;
    ayd = ld * xd[i] * axd * yd[i];
    l = gcd( ayn, ayd );
    debug << "LCD: " << l << endl;
    ayn /= l;
    ayd /= l;
    ayn = ( ayd < 0 ? -ayn : ayn );
    ayd = ( ayd < 0 ? -ayd : ayd );

    // Search for existing point
    found = false;
    for( k = 0; k < s && !found; k++ )
      if( axn == xn[k] && axd == xd[k] && ayn == yn[k] && ayd == yd[k] ){
	m[i][i] = k;
	found = true;
      }
    if( !found ){
      m[i][i] = s;
      xn[s] = axn;
      xd[s] = axd;
      yn[s] = ayn;
      yd[s] = ayd;
      s++;
    }
  }

  // points tripled
  for( i = 0; i < n; i++ ){

    // y1 != 0
    if( !yn[i] ){
      t[i] = -1;
      continue;
    }
    // x1 != x2
    if( xn[m[i][i]] == xn[i] ){
      t[i] = -1;
      continue;
    }
    
    debug << "DEBUG: Checking valid points tripled: [" << (char)( 'A' + i ) << "]\n";

    // Lambda calculation
    ln = ( yn[m[i][i]] * yd[i] - yn[i] * yd[m[i][i]] ) * xd[m[i][i]] * xd[i];
    ld = ( xn[m[i][i]] * xd[i] - xn[i] * xd[m[i][i]] ) * yd[m[i][i]] * yd[i];
    // x-values
    axn = ( ln * ln * xd[i] - xn[i] * ld * ld ) * xd[m[i][i]] - xn[m[i][i]] * ld * ld * xd[i];
    axd = ld * ld * xd[i] * xd[m[i][i]];
    l = gcd( axn, axd );
    debug << "LCD: " << l << endl;
    axn /= l;
    axd /= l;
    axn = ( axd < 0 ? -axn : axn );
    axd = ( axd < 0 ? -axd : axd );
    // y-values
    ayn = ln * ( xn[i] * axd - axn * xd[i] ) * yd[i] - yn[i] * ld * xd[i] * axd;
    ayd = ld * xd[i] * axd * yd[i];
    l = gcd( ayn, ayd );
    debug << "LCD: " << l << endl;
    ayn /= l;
    ayd /= l;
    ayn = ( ayd < 0 ? -ayn : ayn );
    ayd = ( ayd < 0 ? -ayd : ayd );

    // Search for existing point
    found = false;
    for( k = 0; k < s && !found; k++ )
      if( axn == xn[k] && axd == xd[k] && ayn == yn[k] && ayd == yd[k] ){
	t[i] = k;
	found = true;
      }
    if( !found ){
      t[i] = s;
      xn[s] = axn;
      xd[s] = axd;
      yn[s] = ayn;
      yd[s] = ayd;
      s++;
    }
  }

  // Output stuff
  // - The tables
  // --- The two-dimensional table - basic additions
  fout << "--- point-to-point additions of the equation: y^2 = "<< a << "*x^3 + " << b << "*x + " << c << "\n";
  fout << setw( SPACING ) << right << '+' << ' ';
  for( i = 0; i < n; i++ )
    fout << '[' << (char)( 'A' + i ) << "] ";
  fout << endl;
  for( i = 0; i < n; i++ ){
    fout << '[' << (char)( 'A' + i ) << "] ";
    for( j = 0; j < n; j++ )
      if( m[i][j] == -1 )
	fout << setw( SPACING ) << right << '-' << ' ';
      else if( m[i][j] < n )
	fout << setw( SPACING ) << right << (char)( 'A' + m[i][j] ) << ' ';
      else
	fout << setw( SPACING ) << right << m[i][j] << ' ';
    fout << endl;
  }
  // --- The tripled sums
  fout << "\n--- Triplings\n";
  fout << setw( SPACING ) << right << 'x' << ' ';
  for( i = 0; i < n; i++ )
    fout << '[' << (char)( 'A' + i ) << "] ";
  fout << "\n" << setw( SPACING ) << right << "3x" << ' ';
  for( i = 0; i < n; i++ )
    if( t[i] == -1 )
      fout << setw( SPACING ) << right << '-' << ' ';
    else if( t[i] < n )
      fout << setw( SPACING ) << right << (char)( 'A' + t[i] ) << ' ';
    else
      fout << setw( SPACING ) << right << t[i] << ' ';

  // - The points
  fout << "\n\n--- All points\n";
  fout << "- points given\n";
  for( i = 0; i < n; i++ )
    fout << '[' << (char)( 'A' + i ) << "] (" << xn[i] << ", " << yn[i] << ")\n";
  fout << "- New fractional points generated\n";
  for( i; i < s; i++ )
    fout << '[' << setw( SPACING ) << right << i << "] (" << xn[i] << '/' << xd[i] << ", " << yn[i] << '/' << yd[i] << ")\n";

  return 0;
}

long long gcd( long long a, long long b ){

  long long temp;
  if( a > b ){
    temp = a;
    a = b;
    b = temp;
  }
  while( a ){
    temp = b % a;
    b = a;
    a = temp;
  }

  return b;
}
