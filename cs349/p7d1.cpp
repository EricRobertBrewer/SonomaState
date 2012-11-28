/*
p7d1.cpp
Eric Brewer
11/10/10
Watts
CS349 - Programming in a Team Environment
Pebbles - Eliminating the heaviest tile algorithm
*/

#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <stdlib.h>

#define DEBUG 0
#define debug if( DEBUG ) cout

int main(){
  ifstream fin;
  fin.open( "p7d.in" );
  if( fin.fail() ){
    cout << "Error: Couldn\'t open input file.\n";
    exit( 0 );
  }

  ofstream fout;
  fout.open( "p7d1.txt" );
  if( fout.fail() ){
    cout << "Error: Couldn\'t create output file.\n";
    exit( 1 );
  }

  int coord1, coord2, grandtotal, count;
  int i, j, k, l;
  char dud[4];
  fin >> i; fin.getline( dud, 4 );
  const int dheight = (i+4);
  int board[dheight][dheight];
  int sunkenboard[dheight][dheight];
  int oktiles[dheight][dheight];

  // Read physical board
  for( i = 0; i < dheight; i++ )
    for( j = 0; j < dheight; j++ )
      board[i][j] = 0;
  for( i = 2; i < dheight-2; i++ ){
    for( j = 2; j < dheight-2; j++ )
      fin >> board[i][j];
    fin.getline( dud, 4 );
  }

  // Initialize virtual boards
  for( i = 0; i < dheight; i++ )
    for( j = 0; j < dheight; j++ ){      
      sunkenboard[i][j] = board[i][j];
      oktiles[i][j] = 0;
    }
  for( i = 2; i < dheight-2; i++ )
    for( j = 2; j < dheight-2; j++ ){
      for( k = i-1; k < i+2; k++ )
	for( l = j-1; l < j+2; l++ )
	  oktiles[k][l]++;
      oktiles[i][j]--;
    }

  // Sink the sunkenboard - take away from each tile the sum of its neighbors
  grandtotal = 0;
  for( i = 2; i < dheight-2; i++ )
    for( j = 2; j < dheight-2; j++ ){
      for( k = i-1; k < i+2; k++ )
	for( l = j-1; l < j+2; l++ )
	  sunkenboard[k][l] -= board[i][j];
      sunkenboard[i][j] += board[i][j];
      grandtotal += board[i][j];
    }
  
  fout << "Initially...\n";
  for( i = 2; i < dheight-2; i++ ){
    for( j = 2; j < dheight-2; j++ )
      fout << setw(5) << right << board[i][j] << " ";
    fout << "\n\n";
  }
  fout << "\n";
  for( i = 2; i < dheight-2; i++ ){
    for( j = 2; j < dheight-2; j++ )
      fout << setw(5) << right << sunkenboard[i][j] << " ";
    fout << "      ->   ";
    for( k = 2; k < dheight-2; k++ )
      fout << setw(5) << right << oktiles[i][k] << " ";
    fout << "\n\n";
  }
  fout << "\n";
      
  // Big loop - 
  count = 1;
  do{
    
    // Find the first available tile - it becomes the relative heavy
    coord1 = -1;
    coord2 = -1;
    for( i = 2; coord1 < 0 && i < dheight-2; i++ )
      for( j = 2; coord1 < 0 && j < dheight-2; j++ )
	if( oktiles[i][j] > 0 ){
	  coord1 = i;
	  coord2 = j;
	}

    if( coord1 > -1 ){
      
      // Find the heaviest tile within the entire board
      for( i = 2; i < dheight-2; i++ )
	for( j = 2; j < dheight-2; j++ )
	  if( oktiles[i][j] > 0 )
	    if( sunkenboard[i][j] < sunkenboard[coord1][coord2] ){
	      coord1 = i;
	      coord2 = j;
	    }

      // Soften the values surrounding the heaviest tile, This way, we don't
      //  take away a tile's value twice from the grand total. And make our
      //  heavy tile unavailable.

      // Essentially, unsink the sunkenboard
      oktiles[coord1][coord2] = -1;
      for( i = coord1-1; i < coord1+2; i++ )
	for( j = coord2-1; j < coord2+2; j++ ){
	  sunkenboard[i][j] += board[coord1][coord2];
	  if( oktiles[i][j] > 0 )
	    oktiles[i][j]--;
	}
      sunkenboard[coord1][coord2] -= board[coord1][coord2];

      // Take away from the running total
      grandtotal -= board[coord1][coord2];

      // DISPLAY
      fout << "-------------------\n";
      fout << "Iteration: " << count << "\n";
      fout << "Chosen: " << board[coord1][coord2] << "\n";
      fout << "  Row: " << coord1-1 << "  Column: " << coord2-1 << "\n";
      fout << "Running total: " << grandtotal << "\n\n";
      for( i = 2; i < dheight-2; i++ ){
	for( j = 2; j < dheight-2; j++ )
	  fout << setw(5) << right << board[i][j] << " ";
	fout << "\n\n";
      }
      fout << "\n";
      for( i = 2; i < dheight-2; i++ ){
	for( j = 2; j < dheight-2; j++ )
	  fout << setw(5) << right << sunkenboard[i][j] << " ";
	fout << "      ->   ";
	for( k = 2; k < dheight-2; k++ )
	  fout << setw(5) << right << oktiles[i][k] << " ";
	fout << "\n\n";
      }
      // /DISPLAY

      count++;
    }
    
  } while( coord1 > -1 );

  cout << "Grand total: " << grandtotal << "\n";

  return 0;
}
