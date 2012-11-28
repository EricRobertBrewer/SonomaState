#include<iostream>
using namespace std;

#include "MyMakefile.hpp"
#include "systemInterface.h"

int main( int argc, char **argv ) {
  /*
  if( argc != 2 ) {
    std::cerr << argv[0] << ":: usage: " << argv[0] << " aFileName\n";
    return 1;
  }
  */
  // MyMakefile wizard( argv[1] );
  MyMakefile wizard( "Makefile" );
  wizard.runMake();

  wizard.print();

  return 0;
}
