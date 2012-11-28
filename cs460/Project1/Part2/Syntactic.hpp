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
#define debug if( DEBUG ) cout

#define SYNTACTIC_ERROR_OUT 1
#define syntactic_error_out if( SYNTACTIC_ERROR_OUT ) cout

#include <string>
#include <iostream>
using namespace std;

class Lexical;

class Syntactic{

public:
  Syntactic( char *fname );
  void beginParse();
  int getErrors() { return _errors; }


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
  Lexical *_lexical;
       
};

#endif
