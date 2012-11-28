/*
Syntactic.cpp
Eric Brewer
11/19/10
Watts
CS460 - Programming Languages
Syntactic analyzer class implementation - 
*/

#include "Syntactic.hpp"
#include "Lexical.hpp"
#include "parseTable.hpp"
#include "token.hpp"

Syntactic::Syntactic( char *fname ){

  _errors = 0;
  _token = 0;
  _lexical = new Lexical( fname );
}

void Syntactic::beginParse(){
  
  getToken();
  program();
}

void Syntactic::program(){
  debug << "In PROGRAM with token " << tok_names[_token] << endl;
  
  //if( !firsts[_token][PROGRAM] )
  //  error( PROGRAM );

  // Rule 1
  stmt();
  if( _token == SEMI )
    getToken();
  else
    expected( PROGRAM, SEMI );
  more_stmts();
  if( _token != ENDFILE ){
    expected( PROGRAM, ENDFILE );
  }

  return;
}

void Syntactic::more_stmts(){
  debug << "In MORE_STMTS with token " << tok_names[_token] << endl;

  //if( !firsts[_token][MORE_STMTS] )
  //  error( MORE_STMTS );

  // Rule 3
  if( follows[_token][MORE_STMTS] ){}
  else if( firsts[_token][STMT] ){
    // Rule 2
    stmt();
    if( _token == SEMI )
      getToken();
    else
      expected( MORE_STMTS, SEMI );
    more_stmts();
  }
  else
    error( MORE_STMTS );

  return;
}

void Syntactic::stmt(){
  debug << "In STMT with token " << tok_names[_token] << endl;

  //if( !firsts[_token][STMT] )
  //  error( STMT );

  // Rule 4
  term();
  stmt_tail();

  return;
}

void Syntactic::term(){
  debug << "In TERM with token " << tok_names[_token] << endl;

  //if( !firsts[_token][TERM] )
  //  error( TERM );

  if( _token == LPAREN ){
    // Rule 6
    getToken();
    stmt();
    if( _token == RPAREN )
      getToken();
    else
      expected( TERM, RPAREN );
  }
  else if( firsts[_token][PRE] ){
    // Rule 5
    pre();
    var();
    post();
  }
  else
    error( TERM );

  return;
}

void Syntactic::pre(){
  debug << "In PRE with token " << tok_names[_token] << endl;

  //if( !firsts[_token][PRE] )
  //  error( PRE );

  // Rule 8
  if( follows[_token][PRE] ){}
  else if( firsts[_token][UOPPRE] ){
    // Rule 7
    uoppre();
    pre();
  }else
    error( PRE );

  return;
}

void Syntactic::uoppre(){
  debug << "In UOPPRE with token " << tok_names[_token] << endl;

  //if( !firsts[_token][UOPPRE] )
  //  error( UOPPRE );

  // Rules 9-16
  if( _token == PL || _token == MIN || _token == MULT || _token == LOGNOT ||
      _token == AND || _token == ONESCOMP || _token == PLPL || _token == MINMIN )
    getToken();
  else
    error( UOPPRE );

  return;
}

void Syntactic::var(){
  debug << "In VAR with token " << tok_names[_token] << endl;

  //if( !firsts[_token][VAR] )
  //  error( VAR );

  // Rules 17, 18
  if( _token == IDENT || _token == INT || _token == REAL )
    getToken();
  else
    error( VAR );

  return;
}

void Syntactic::post(){
  debug << "In POST with token " << tok_names[_token] << endl;

  //if( !firsts[_token][POST] )
  //  error( POST );

  // Rule 21
  if( follows[_token][POST] ){}
  else if( _token == PLPL || _token == MINMIN )
    // Rules 19, 20
    getToken();
  else
    error( POST );

  return;
}

void Syntactic::stmt_tail(){
  debug << "In STMT_TAIL with token " << tok_names[_token] << endl;

  //if( !firsts[_token][STMT_TAIL] )
  //  error( STMT_TAIL );

  // Rule 24
  if( follows[_token][STMT_TAIL] ){}
  else if( _token == QUESTION ){
    // Rule 23
    getToken();
    stmt();
    if( _token == COLON )
      getToken();
    else
      expected( STMT_TAIL, COLON );
    stmt();
  }
  else if( firsts[_token][BINOP] ){
    // Rule 22
    binop();
    stmt();
  }else
    error( STMT_TAIL );

  return;
}

void Syntactic::binop(){
  debug << "In BINOP with token " << tok_names[_token] << endl;

  // Rules 25-54
  if( firsts[_token][BINOP] )
    getToken();
  else
    error( BINOP );
  
  return;
}

int Syntactic::getToken(){

  _token = _lexical->getToken();
  
  return _token;
}

void Syntactic::error( int nonterminal ){

  syntactic_error_out << "\tError: Line[" << _lexical->getLineNo() << 
    "], Character[" << _lexical->getPos() <<
    "], Lexeme[" << _lexical->getLexeme() <<
    "]: in nonterminal " << non_terminal_names[nonterminal] << 
    " with token " << tok_names[_token] << "\n";
  
  _errors++;  
  findFollows( nonterminal );

  return;
}

void Syntactic::expected( int nonterminal, int terminal ){

  syntactic_error_out << "\tExpected: Line[" << _lexical->getLineNo() << 
    "], Character[" << _lexical->getPos() <<
    "], Lexeme[" << _lexical->getLexeme() <<
    "]: in nonterminal " << non_terminal_names[nonterminal] <<
    " should be " << tok_names[terminal] << 
    ", instead received " << tok_names[_token] << "\n";

  _errors++;
  findFollows( nonterminal );

  return;
}

void Syntactic::findFollows( int nonterminal ){
  
  do
    getToken();
  while( !(_lexical->getEndfile() ) && !follows[_token][nonterminal] );

  return;
}
