/*
Lexical.hpp
Eric Brewer
10/19/10
Watts
CS460 - Programming Languages
Lexical analyzer class header - 
*/

#ifndef LEXICAL_HPP
#define LEXICAL_HPP

#define LEXICAL_LINE_PRINT 1
#define lexical_line_print if( LEXICAL_LINE_PRINT ) cout

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
#include <cstdlib>

class Lexical{
  
public:
  Lexical( char *fname );

  int getToken();
  string getLexeme() { return _lexeme; }
  int getLastToken() { return _last_token; }
  int getLineNo() { return _line_no; }
  int getPos() { return _pos; }
  bool getEndfile();
  bool openFile();
  bool closeFile();

private:

  ifstream _ins;
  string _filename;
  // Holds the last lexeme read by getToken.
  string _lexeme;
  int _last_token;
  string _text;
  int _pos;
  int _line_no;

};

#endif
