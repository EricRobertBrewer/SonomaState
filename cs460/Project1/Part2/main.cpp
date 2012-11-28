/*
main.cpp
Eric Brewer
11/18/10
Watts
CS460 - Programming Languages
Main - 
*/

#include <iostream>
using namespace std;
#include <fstream>
#include <stdlib.h>
#include "Syntactic.hpp"

int main( int argc, char *argv[] ){

  if( argc != 2 ){
    cout << "Incorrect number of arguments.\n";
    cout << "Usage: " << argv[0] << " <filename>\n";
    exit( 0 );
  }

  Syntactic *syn = new Syntactic( argv[1] );
  syn->beginParse();

  cout << "Errors: " << syn->getErrors() << endl;

  return 0;
}
