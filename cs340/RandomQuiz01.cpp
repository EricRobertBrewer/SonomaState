/*
RandomQuiz01.cpp
Eric Brewer
2/7/12
Random Quiz 01 - 
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define DEBUG 0
#define debug if( DEBUG ) cout

#define MAX_LENGTH 254
#define KEY_LENGTH 80

enum method{ UNKNOWN, CAESARS, SCYTALE, PLAYFAIR, VIGENERE };
char** play_grid[5][5];

void Caesars( char* pt );
void Scytale( char* pt );
void Playfair( char* pt, char* key );
void Vigenere( char* pt, char* key );

int main( int argc, char* argv[] ){

  if( argc != 2 ){
    cout << "Error: 2 arguments needed:  " << argv[0] << " <inputfile>\n";
    exit( 1 );
  }

  ifstream fin( argv[1] );
  if( fin.fail() ){
    cout << "Error: input file not found.\n";
    exit( 2 );
  }

  int rounds;
  int method_id;
  char dud[80];
  char cipherkey[KEY_LENGTH];
  char plaintext[MAX_LENGTH];
  
  fin >> rounds;

  for( rounds; rounds; rounds-- ){

    fin >> method_id;
    fin.getline( dud, 80 );

    switch( method_id ){

    case 0:
      break;

    case 1:
      fin.getline( plaintext, MAX_LENGTH );
      Caesars( plaintext );
      break;

    case 2:
      fin.getline( plaintext, MAX_LENGTH );
      Scytale( plaintext );
      break;

    case 3:
      fin.getline( cipherkey, KEY_LENGTH );
      fin.getline( plaintext, MAX_LENGTH );
      Playfair( plaintext, cipherkey );
      break;

    case 4:
      fin.getline( cipherkey, KEY_LENGTH );
      fin.getline( plaintext, MAX_LENGTH );
      Vigenere( plaintext, cipherkey );
      break;
    }
  }

  return 0;
}

void Caesars( char* pt ){

  cout << "Caesars: \n\t";
  for( int i = 0; i < strlen( pt ); i++ ){

    if( pt[i] == ' ' )
      cout << ' ';
    else
      cout << ( (char)( ( toupper( pt[i] ) - 'A' - 3 ) % 26 ) + 'A' );
  }
  cout << endl;
}

void Scytale( char* pt ){

  cout << "Scytale: \n\t";

  // Strip spaces
  char ct[MAX_LENGTH];
  for( int i = 0, j = 0; i < strlen( pt ); i++ )
    if( pt[i] != ' ' ){
      ct[j] = pt[i];
      j++;
    }

  for( int i = 3; i < 25; i++ ){

    for( int j = 0; j < strlen( ct ); j++ ){
      
      if( pt[i] == ' ' )
	cout << ' ';
      else
	;
    }
    cout << endl;
  }
}

void Playfair( char* pt, char* key ){

  cout << "Playfair: \n\t";

  cout << endl;
}

void Vigenere( char* pt, char* key ){

  cout << "Vigenere: \n\t";

  cout << endl;
}
