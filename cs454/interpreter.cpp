//Carissa Wacker, Eric Brewer
//Interpreter.cpp
//Parses through allPrimes.txt and prints out different sets of primes


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;

void isPrimeInit ( bool a[], int size );
void primesFill ( unsigned int a[], int &size, ifstream &inFile );
void twinPrimes ( unsigned int a[], int size );
void primeEndings1 ( unsigned int a[], int size );
void primeEndings2 ( unsigned int a[], int size );
void primeEndings3 ( unsigned int a[], int size );
void print ( unsigned int a[], int size );
void findUpperBoundIndex( unsigned int a[], int &index, int upper_bound, int size );
bool checkPrimality( unsigned int a[], int tester, int size );
bool checkPr( unsigned int a[], int tester, int low, int high );

//#define SIZE 1200000
#define DEBUG 0
#define debug if( DEBUG ) cout

int main ()
{
  ifstream inFile ( "allPrimes.txt" );
  if ( inFile.fail() )
    exit(1);

  int size = 0;

  int numprimes;
  inFile >> numprimes;
  const int NUMPRIMES = numprimes;

  unsigned int *primes = new unsigned int[NUMPRIMES];
  
  primesFill ( primes, size, inFile );
  inFile.close();
  
  twinPrimes ( primes, size );
  primeEndings1( primes, size );
  primeEndings2( primes, size );
  primeEndings3( primes, size );

  int myX;
  int indexX;
  int nth;
  int candidate;

  char input;
  while ( true ) {
    cout << "\n--------------------\n"
	 << "Options:\n" 
	 << "1: Upper bound\n" 
	 << "2: Nth prime\n"
	 << "3: Primality check\n" 
	 << "0: Quit\n";
    cin >> input;
    switch ( input ) {

    case '1':
      cout << "Your upper bound:\n";
      cin >> myX;
      cout << "Number of primes : Largest prime within bound\n";
      findUpperBoundIndex( primes, indexX, myX, size );
      cout << indexX << " : " << primes[indexX-1] << endl;
      cout << "ratio: " << (float)indexX / primes[indexX-1] << endl;
      break;
    case '2':
      cout << "Nth prime:\n";
      cin >> nth;
      cout << primes[nth] << endl;
      break;
    case '3':
      cout << "Which number?\n";
      cin >> candidate;
      if( checkPrimality( primes, candidate, size ) )
	cout << candidate << " is prime.\n";
      else
	cout << candidate << " is not prime.\n";
      break;
    case '0':
      return 0;
    }
  }
}

void isPrimeInit ( bool a[], int size )
{
  for (int i = 0; i < size; i++)
    a[i] = false;
}

void primesFill ( unsigned int a[], int &size, ifstream &inFile )
{
  cout << "Populating array...\n";
  unsigned int n;
  //inFile >> n;
  while ( inFile >> n )
    {
      a[size] = n;
      size ++;
    }
  cout << "Done.\n";
}

void twinPrimes ( unsigned int a[], int size )
{
  cout << "Writing \"twin.txt\"...\n";
  ofstream out;
  out.open ("twin.txt");
  out << "2 3" << endl;
  for (int i = 0; i < size - 1; i++)
    {
      if ( a[i+1] - a[i] == 2 )
	out << a[i] << " " << a[i+1] << endl;
    }
  out.close ();
  cout << "Done.\n";
}

void primeEndings1 ( unsigned int a[], int size )
{
  cout << "Writing \"ones.txt\"...\n";
  ofstream out;
  out.open( "ones.txt" );
  int one, three, seven, nine;
  one = three = seven = nine = 0;

  for ( int i = 0; i < size; i++ )
    {
      int b = ( a[i] % 10 );
      if ( b == 1 )
	one++;
      else if ( b == 3 )
	three++;
      else if ( b == 7 )
	seven++;
      else if ( b == 9 )
	nine++;
    }
  out << "Number of primes ending in ... \n";
  out << "1: " << one << endl;
  out << "3: " << three << endl;
  out << "7: " << seven << endl;
  out << "9: " << nine << endl << endl;
  out << "Percent of primes ending in ... \n";
  out << "1: " << 1.0 * one/size * 100 << endl;
  out << "3: " << 1.0 * three/size * 100 << endl;
  out << "7: " << 1.0 * seven/size * 100 << endl;
  out << "9: " << 1.0 * nine/size * 100 << endl;
  out.close();
  cout << "Done.\n";
}

void primeEndings2 ( unsigned int primes[], int size ) {
  cout << "Writing \"tens.txt\"...\n";
  ofstream out;
  out.open( "tens.txt" );
  int a[100];
  for (int i = 0; i < 100; i++)
    a[i] = 0;

  for ( int i = 0; i < size; i++) {
    int idx = primes[i] % 100;
    a[idx]++;
  }
  out << "Percent of primes ending in ... \n";
  out << "01: " << (float)a[1]/size*100 << endl;
  out << "03: " << (float)a[3]/size*100 << endl;
  out << "07: " << (float)a[7]/size*100 << endl;
  out << "09: " << (float)a[9]/size*100 << endl;
  for ( int i = 10; i < 100; i++ ) {
    if ( a[i] != 0 ) {
      out << i << ": " << (float)a[i]/size*100 << endl;
    }
  }
  out.close();
  cout << "Done.\n";
}

void primeEndings3 ( unsigned int primes[], int size ) {
  cout << "Writing \"hundreds.txt\"...\n";
  ofstream out;
  out.open( "hundreds.txt" );
  int a[1000];
  for (int i = 0; i < 1000; i++)
    a[i] = 0;

  for ( int i = 0; i < size; i++) {
    int idx = primes[i] % 1000;
    a[idx]++;
  }
  out << "Percent of primes ending in ... \n";
  out << "001: " << (float)a[1]/size*100 << endl;
  out << "003: " << (float)a[3]/size*100 << endl;
  out << "007: " << (float)a[7]/size*100 << endl;
  out << "009: " << (float)a[9]/size*100 << endl;
  for ( int i = 10; i < 1000; i++ ) {
    if ( a[i] != 0 ) {
      if( i < 100 )
	out << '0';
      out << i << ": " << (float)a[i]/size*100 << endl;
    }
  }
  out.close();
  cout << "Done.\n";
}

void print ( unsigned int a[], int size )
{
  cout << "First " << size << " primes.\n";
  primeEndings1 ( a, size );
}

void findUpperBoundIndex( unsigned int a[], int &index, int upper_bound, int size ){

  for( index = 0; index < size && a[index] <= upper_bound; index++ );
}

bool checkPrimality( unsigned int a[], int tester, int size ){

  if( !( tester % 2 ) )
    return false;

  return checkPr( a, tester, 0, size-1 );
}

bool checkPr( unsigned int a[], int tester, int low, int high ){

  if( low > high )
    return false;

  int middle = ( low + high ) / 2;
  if( tester == a[middle] )
    return true;
  else if( tester < a[middle] )
    return checkPr( a, tester, low, middle-1 );
  else
    return checkPr( a, tester, middle+1, high );
}
