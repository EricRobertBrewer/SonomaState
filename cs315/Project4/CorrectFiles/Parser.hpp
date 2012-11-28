#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <string>
using namespace std;

class Parser{

public:
  Parser();
  Parser( string f );
  ~Parser();
  
  void walkUntil( char c );
  bool matchNext( char c );
  bool matchNext( string s );
  string readString();
  string readStringUntil( char c );

  void open( string f );
  void close();

  bool eof() { return !fin.good(); }
  string fileName() { return _fileName; }

private:
  ifstream fin;
  string _fileName;
  char in_char;
  string in_string;

};

#endif
