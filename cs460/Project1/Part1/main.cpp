/*
main.cpp
Eric Brewer
10/19/10
Watts
CS460
Main -
 */

#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
#include <fstream>
#include <stdlib.h>
#include "token.hpp"

int main( int argc, char *argv[] ){

  // Correct format, file open error
  if( argc != 2 ){
    cout << "Incorrect number of arguments.\n";
    cout << "Usage: " << argv[0] << " <filename>\n";
    exit( 1 );
  }
  ifstream fin;
  fin.open( argv[1] );
  if( fin.fail() ){
    cout << "Cannot open file " << argv[1] << ".\n";
    exit( 1 );
  }

  int result;
  enum TOKEN token;

  do{

    result = getToken( fin );
    cout << '\t' << tok_names[result] << '\t' << getLexeme() << endl;

  } while( !fin.eof() );

  fin.close();
  
  return 0;
}

