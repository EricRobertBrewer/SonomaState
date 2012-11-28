/*
Symbol.cpp
Eric Brewer
12/19/10
Watts
CS460 - Programming Languages
Symbol class implementation - 
*/

#include "Symbol.hpp"
#include "token.hpp"

Symbol::Symbol() {}

ostream& operator << ( ostream& outs, const Symbol & sym ){

  sym.write( outs );
  return outs;
}

Operator::Operator() {}

Operator::Operator( string n, int tok ){

  _name = n;
  _tokenid = tok;
}

void Operator::write( ostream& outs ) const{

  outs << _name << "\t" 
       << precedence[_tokenid] << "\t"
       << ( lefttoright[_tokenid] ? "left -> right" : "right -> left" );
}

void Literal::setFloat( bool f ){
  
  _isfloat = f;
}

Integer::Integer(){

  _isfloat = false;
  _value = 0;
  _tokenid = INT;
}

Integer::Integer( string n ){

  _name = n;
  _isfloat = false;
  _value = atoi( _name.c_str() );
  _tokenid = INT;
}

Integer::Integer( int val ){
  
  _value = val;
  _name = "";
  _isfloat = false;
  _tokenid = INT;
}

void Integer::write( ostream& outs ) const{

  outs << _value;
}

Real::Real(){

  _isfloat = true;
  _value = 0.0;
  _tokenid = REAL;
}

Real::Real( string n ){

  _name = n;
  _isfloat = true;
  _value = atof( _name.c_str() );
  _tokenid = REAL;
}

Real::Real( float val ){

  _value = val;
  _name = "";
  _isfloat = true;
  _tokenid = REAL;
}

void Real::write( ostream& outs ) const{

  outs.setf( ios::fixed );
  outs.setf( ios::showpoint );
  outs.precision( 5 );
  outs << _value;
}

Identifier::Identifier(){

  _innards = NULL;
  _tokenid = IDENT;
}

Identifier::Identifier( string n, Literal* lp ){

  _name = n;
  _innards = lp;
  _tokenid = IDENT;
}

void Identifier::write( ostream& outs ) const{

  outs << _name << "\t";
  if( _innards )
    _innards->write( outs );
}

void Identifier::setValue( Literal* lp ){
  
  _innards = lp;
}

bool Identifier::isFloat(){

  if( _innards )
    return _innards->isFloat();

  return false;
}

void Identifier::setFloat( bool f ){

  if( _innards )
    _innards->setFloat( f );
}

size_t Identifier::value(){

  if( _innards )
    return _innards->value();

  return 0;
}
