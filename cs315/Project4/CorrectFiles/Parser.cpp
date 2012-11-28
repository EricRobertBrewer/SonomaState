#include "Parser.hpp"

Parser :: Parser(){
  _fileName = "";
  in_char = ' ';
  in_string = "";
}

Parser :: Parser( string f ){
  _fileName = f;
  const char *s = f.c_str();
  fin.open( s );
  in_char = ' ';
  in_string = "";
}

Parser :: ~Parser(){
  fin.close();
}

void Parser :: walkUntil( char c ){
  while( fin.get( in_char ) && in_char != c );
}

bool Parser :: matchNext( char c ){
  while( fin.get( in_char ) && in_char != ' ' && in_char != '\n' && in_char != '\t' );
  return in_char == c;
}

bool Parser :: matchNext( string s ){
  bool b = true;
  while( fin.get( in_char ) && in_char != ' ' && in_char != '\n' && in_char != '\t' );
  fin.unget();
  for( int i = 0; i < s.length() && b; i++ )
    if( fin.get( in_char ) && in_char != s[i] )
      b = false;
  return b;
}

string Parser :: readString(){
  fin >> in_string;
  return in_string;
}

string Parser :: readStringUntil( char c ){
  in_string = "";
  while( fin.get( in_char ) && in_char != c ){
    in_string += in_char;
  }
  fin.unget();
  return in_string;
}

void Parser :: open( string f ){
  if( fin.is_open() )
    fin.close();
  const char *s = f.c_str();
  fin.open( s );
  _fileName = f;
}

void Parser :: close(){
  fin.close();
}
