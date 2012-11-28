/*
Parser.hpp
Eric Brewer
12/5/10
Kooshesh
CS450 - Operating Systems
Parser header - 
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
using namespace std;
#include <string>

#define MAX_LINE 1024
#define MAX_LEXEME 256

class Parser{

public:
  Parser();
  
  string getNextLexeme();
  void setLine( string line );
  bool eol();
  string getLastLexeme() { return _lexeme; }
  int getPos() { return _pos; }
  
private:
  string _line;

  string _lexeme;
  int _pos;

};

#endif
