/*
9fg.cpp
Stephen Gulland
Eric Brewer
12/8/10
CS349 - Programming in a Team Environment
Crazy Minesweeper - 
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include <cmath>
#include <iomanip>

#define MAX 100
#define DEBUG 1
#define debug if( DEBUG ) cout

int main( int argc, char *argv[] ){

  ifstream fin;
  fin.open( "9fg.txt" );
  if( fin.fail() ){
    cout << "File open error.\n";
    exit( 1 );
  }
  
  int num_maps, bound, mapsize, first, second, x1, x2, y1, y2, pox, poy, centerx, centery;
  int diffx, diffy;
  int table[MAX][MAX];
  fin >> num_maps;
  for( num_maps; num_maps; num_maps-- ){
    
    fin >> bound;
    fin >> first;
    fin >> second;

    mapsize = ( sqrt( bound ) + 1 );
    for( int i = 0; i < mapsize; i++ )
      for( int j = 0; j < mapsize; j++ )
	table[i][j] = 0;

    if( mapsize % 2 )
      {
	int half = mapsize/2;
	pox = half;
	poy = half;
      }
    else
      {
      pox = (mapsize/2) - 1;
      poy = (mapsize/2) - 1;
      }

    int mcase = 1;
    int count = 1;
    table[pox][poy] = 1;
    poy++;
    count = 2;
    while( count <= bound )
      {
	table[poy][pox] = count;
	if( mcase == 1)
	  {
	    if( table[poy][pox-1] == 0)
	      {
		mcase = 2;
		pox--;
	      }
	    else
	      {
		poy++;
	      }
	  }
	else if(mcase == 2)
	  {
	    if( table[poy-1][pox] == 0 )
	      {
		mcase = 3;
		poy--;
	      }
	    else
	      {
		pox--;
	      }
	  }
	else if(mcase == 3)
	  {
	    if(table[poy][pox+1] == 0)
	      {
		mcase = 4;
		pox++;
	      }
	    else
	      {
		poy--;
	      }
	  }
	else if(mcase == 4)
	  {
	    if( table[poy+1][pox] == 0)
	      {
		mcase = 1;
		poy++;
	      }
	    else
	      {
		pox++;
	      }
	  }
	count++;
      }

    for( int i = 0; i < mapsize; i++ ){
      for( int j = 0; j < mapsize; j++ )
	{
	  if( table[i][j] == first)
	    {
	      y1 = i;
	      x1 = j;
	    } 
	  else if( table[i][j] == second)
            {
	      y2 = i;
	      x2 = j;
            }
	}
    }
    diffy = y1 - y2;
    diffx = x1 -x2;
    cout << setprecision( 6 ) << sqrt( ( diffx * diffx ) + ( diffy * diffy ) ) << endl;
    
  }

  return 0;
}
