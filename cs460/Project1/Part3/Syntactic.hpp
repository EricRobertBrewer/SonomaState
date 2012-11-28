/*
Syntactic.hpp
Eric Brewer
11/19/10
Watts
CS460 - Programming Languages
Syntactic analyzer class header - 
*/

#ifndef SYNTACTIC_HPP
#define SYNTACTIC_HPP

#define DEBUG 1
#define debug if( DEBUG ) _fout

#define SYNTACTIC_ERROR_OUT 1
#define syntactic_error_out if( SYNTACTIC_ERROR_OUT ) cout

#include <string>
#include <iostream>
using namespace std;
#include <vector>
#include <fstream>

class Lexical;

class Syntactic{

public:
  Syntactic( char *fname );
  void beginParse();
  int getErrors() { return _errors; }
  vector< int >* tokens() { return _tokenlist; }
  vector< string >* lexemes() { return _lexemelist; }

private:
  void program();
  void more_stmts();
  void stmt();
  void term();
  void pre();
  void uoppre();
  void var();
  void post();
  void stmt_tail();
  void binop();

  int getToken();
  void error( int nonterminal );
  void expected( int nonterminal, int terminal );
  void findFollows( int nonterminal );

  int _errors;
  int _token;
  ofstream _fout;
  Lexical* _lexical;
  vector< int >* _tokenlist;
  vector< string >* _lexemelist;

};

#endif
