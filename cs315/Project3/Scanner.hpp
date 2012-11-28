#ifndef SCANNER_HPP
#define SCANNER_HPP

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include "Token.hpp"
using namespace std;

class Scanner{
public:
  Scanner();
  void open();
  void open( string file );
  Token getToken();
  string readCommand();
  string &fileName() { return _fileName; }

private:
  void skipCommentLine();

private:
  ifstream fin;
  string _fileName;
};

#endif
