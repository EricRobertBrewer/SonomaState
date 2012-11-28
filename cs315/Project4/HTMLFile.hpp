#ifndef HTML_FILE_HPP
#define HTML_FILE_HPP

#include "AnchorTag.hpp"

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class HTMLFile{

public:
  HTMLFile();
  HTMLFile( string f );

  bool insertOutTag( AnchorTag *a );
  bool insertInFile( HTMLFile *h );
  void print();

  string &nameOfFile() { return file; }

private:
  string file;
  vector<AnchorTag*> outgoingtags;
  vector<HTMLFile*> incomingfiles;

};

#endif
