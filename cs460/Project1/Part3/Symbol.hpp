/*
Symbol.hpp
Eric Brewer
12/19/20
Watts
CS460 - Programming Languages
Symbol class header - 
*/

#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <string>
#include <iostream>
using namespace std;
#include <iomanip>
#include <cstdlib>

class Literal;

class Symbol{
public:
  Symbol();
  virtual void write( ostream& outs ) const {}
  friend ostream& operator << ( ostream& outs, const Symbol& sym );
  string getName() { return _name; }
  int getTokenID() { return _tokenid; }
  virtual bool isFloat() {}
  virtual size_t value() {}
  virtual void setValue( Literal *lp ) {}
  virtual void setFloat( bool f ) {}

protected:
  string _name;
  int _tokenid;

};

class Operator : public Symbol{
public:
  Operator();
  Operator( string n, int tok );
  void write( ostream& outs ) const;

};

class Literal : public Symbol{
public:
  bool isFloat() { return _isfloat; }
  void setFloat( bool f );

protected:
  bool _isfloat;

};

class Integer : public Literal{
public:
  Integer();
  Integer( string n );
  Integer( int val );
  void write( ostream& outs ) const;
  size_t value() { return _value; }

private:
  int _value;

};

class Real : public Literal{
public:
  Real();
  Real( string n );
  Real( float val );
  void write( ostream& outs ) const;
  size_t value() { return _value; }

private:
  float _value;

};

class Identifier : public Symbol{
public:
  Identifier();
  Identifier( string n, Literal* lp );
  void write( ostream& outs ) const;
  void setValue( Literal* lp );
  bool isFloat();
  void setFloat( bool f );
  size_t value();

private:
  Literal* _innards;

};

#endif

  
