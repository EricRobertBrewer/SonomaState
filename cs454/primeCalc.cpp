/*
primeCalc.cpp
Eric Brewer
11/21/10
Ledin
CS454 - Theory of Computation
Prime calculation - 
*/

#include <iostream>
using namespace std;
#include <cmath>
#include <fstream>

#define ARRAY_SIZE 14000000
#define LARGEST_INT 4000000000

int main( int argc, char *argv[] ){

  ofstream fout;
  fout.open( "allPrimes.txt" );
  if( fout.fail() ){
    cout << "File open error.\n";
    return 1;
  }

  cout << "Building table of primes...\n";

  unsigned int *primes = new unsigned int[ARRAY_SIZE];
  primes[0] = 2;
  primes[1] = 3;
  primes[2] = 5;
  primes[3] = 7;

  int index;
  bool found;

  index = 4;
  for( int j = primes[index-1]+2; j < LARGEST_INT && index < ARRAY_SIZE; j+=2 ){
    found = false;
    for( int i = 1; primes[i]-1 < sqrt( j ) && !found; i++ )
      if( !( j % primes[i] ) )
	found = true;
    if( !found ){
      primes[index] = j;
      index++;
    }
  }

  cout << "Completed prime table. " << index << " primes found.\n";

  fout << index << endl;
  for( int i = 0; i < ARRAY_SIZE; i++ )
    fout << primes[i] << endl;

  return 0;
}
