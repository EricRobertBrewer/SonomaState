/*
d.cpp
Team 13
Eric Brewer, Vinh Gruenhagen, Stephen Gulland
 */

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
#include <fstream>

#define DEBUG 0
#define debug if(DEBUG) cout

bool recurse( int highbound, int lowtarget, int hightarget );

int insects[150];

int main(){

  ifstream fin( "d.in" );
  if( fin.fail() )
    exit( 0 );

  int count;
  int lo;
  int hi;
  int numbugs;
  char s[256];

  fin >> count;
  fin.getline( s, 256 );

  for( int j = 0; j < count; j++ ){
    fin >> lo;
    fin >> hi;
    fin >> numbugs;
    for( int i = 0; i < numbugs; i++ )
      fin >> insects[i];

    debug << lo << endl;
    debug << hi << endl;
    debug << numbugs << endl;
    debug << insects[numbugs-1] << endl;

    if( recurse( numbugs-1, lo, hi ) )
      cout << "Sallow swallow swallows." << endl;
    else
      cout << "Sallow swallow wallows in dust." << endl;
    fin.getline( s, 256 );
  }

  return 0;
}

bool recurse( int highbound, int lowtarget, int hightarget ){

  debug << highbound << ' ' << lowtarget << ' ' << hightarget << endl;

  if( !(highbound+1) )
    return false;

  if( insects[highbound] >= lowtarget && insects[highbound] <= hightarget )
    return true;
  
  if( insects[highbound] > hightarget )
    return recurse( highbound-1, lowtarget, hightarget );
  
  return recurse( highbound-1, lowtarget-insects[highbound], hightarget-insects[highbound] );
}
