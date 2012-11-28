/*
k.cpp
Eric Brewer
12-1-10
Watts
CS349 - Programming in a Team Environment
Zombie Blast -
*/

#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>

#define DEBUG 0
#define debug if( DEBUG ) cout 

#define MAX_HEIGHT  2000
#define MAX_WIDTH   2000
#define MAX_M      20000
#define MAX_Z      20000
#define coordX         0
#define coordY         1

int main( int argc, char *argv[] ){

  ifstream fin( "k.in" );
  if( fin.fail() ){
    cout << "File open error.\n";
    exit( 1 );
  }

  char dud[4];
  int num_maps, height, width, num_mines, num_zombies;
  char map[MAX_HEIGHT][MAX_WIDTH];
  int mines[MAX_M][2];
  int zombies[MAX_Z][2];
  int closest_m[MAX_Z];
  int temp;
  int farthest_closest;

  fin >> num_maps; fin.getline( dud, 4 );
  
  for( num_maps; num_maps; num_maps-- ){

    debug << "num_maps: " << num_maps << endl;

    fin >> width;
    fin >> height; fin.getline( dud, 4 );
    
    // Discover the numbers of mines and zombies and grab their coordinates.
    num_mines = 0;
    num_zombies = 0;
    for( int i = 0; i < height; i++ ){
      for( int j = 0; j < width; j++ ){
	fin >> map[i][j];
	if( map[i][j] == 'M' ){
	  mines[num_mines][coordY] = i;
	  mines[num_mines][coordX] = j;
	  num_mines++;
	}
	else if( map[i][j] == 'Z' ){
	  zombies[num_zombies][coordY] = i;
	  zombies[num_zombies][coordX] = j;
	  num_zombies++;
	}
      }
      fin.getline( dud, 4 );
    }

    debug << "num_mines: " << num_mines << endl;
    debug << "num_zombies: " << num_zombies << endl;

    // For each zombie, determine the closest mine from that zombie.
    for( int i = 0; i < num_zombies; i++ )
      closest_m[i] = ( ( zombies[i][coordY] - mines[0][coordY] ) * ( zombies[i][coordY] - mines[0][coordY] ) +
		       ( zombies[i][coordX] - mines[0][coordX] ) * ( zombies[i][coordX] - mines[0][coordX] ) );
    for( int i = 0; i < num_zombies; i++ )
      for( int j = 1; j < num_mines; j++ ){
	temp = ( ( zombies[i][coordY] - mines[j][coordY] ) * ( zombies[i][coordY] - mines[j][coordY] ) +
		 ( zombies[i][coordX] - mines[j][coordX] ) * ( zombies[i][coordX] - mines[j][coordX] ) );
	if( temp < closest_m[i] )
	  closest_m[i] = temp;
      }

    debug << "temp: " << temp << endl;
    debug << "closest_m[0]: " << closest_m[0] << endl;

    // Now, determine the longest closest zombie-to-mine distance. This is the answer.
    farthest_closest = closest_m[0];
    for( int i = 1; i < num_zombies; i++ )
      if( closest_m[i] > farthest_closest )
	farthest_closest = closest_m[i];

    cout << fixed << setprecision( 6 ) << sqrt( farthest_closest ) << endl;
  }
  
  return 0;
}
