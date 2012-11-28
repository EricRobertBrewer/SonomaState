#include <string>

#include "TagReader.hpp"

int main( int argc, char** argv ){

  TagReader reader;

  string s = argv[1];
  reader.scanInputFile( s );

  reader.print();

  return 0;

}
