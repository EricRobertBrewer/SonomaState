/*
Parser.cpp
Eric Brewer
12/5/10
Kooshesh
CS450 - Operating Systems
Parser implementation - 
*/

#include "Parser.hpp"

Parser::Parser(){

  _line = " ";
  _lexeme = "";
  _pos = 0;
}

string Parser::getNextLexeme(){

  if( eol() )
    return _lexeme;

  _lexeme = "";

  // Skips white space
  for( _pos; _pos < _line.length() && isspace( _line[_pos] ); _pos++ );

  // Grabs a continious string of non-space characters
  for( _pos; _pos < _line.length() && !isspace( _line[_pos] ); _pos++ )
    _lexeme += _line[_pos];

  return _lexeme;
}

void Parser::setLine( string line ){

  _line = line;
  _pos = 0;
}

bool Parser::eol(){

  return _pos == _line.length();
}
