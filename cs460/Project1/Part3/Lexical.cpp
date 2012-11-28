/*
Lexical.cpp
Eric Brewer
10/20/10
Watts
CS460 - Programming Languages
Lexical analyzer class implementation - 
*/

#include "Lexical.hpp"
#include "stateTable.hpp"
#include "token.hpp"

Lexical::Lexical( char *fname ){

  _ins.open( fname );
  if( _ins.fail() ){
    cout << "File open error: " << fname << endl;
    exit( 1 );
  }
  _filename = fname;
  _lexeme = "";
  _last_token = 0;
  _text = " ";
  _pos = 0;
  _line_no = 0;
}

int Lexical::getToken(){

  _lexeme = "";
  int state, a;

  // Bypassing white space, marches along the file, one line at a time
  while( isspace( _text[_pos] ) ){
    _pos++;
    if( _pos >= _text.length() ){

      getline( _ins, _text );
      _line_no++;
      lexical_line_print << "[" << _line_no << "]  " << _text << endl;
      if( _ins.eof() )
	return ENDFILE;
      if( _ins.fail() )
	return ERROR;
      _text += " ";
      _pos = 0;
    }
  }

  // Starting in state 1, use the state table and the received character to determine 
  //  the next state.
  state = 1;
  while( state > 0 ){
    // March 'a' along our alphabet until we fall off or until we hit the character we 
    //  are looking at.
    for( a = 0; a < SPYING_CHARACTER && alphabet[a] != _text[_pos]; a++ );
    state = state_table[a][state];
    _lexeme += _text[_pos];
    _pos++;
  }

  // In the cases where we have to look one character beyond to know that our lexeme has 
  //  finished, we must put back that last taken character.
  switch( -state ){
  case PL: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case MIN: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case MULT: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case DIV: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case MOD: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case EQ: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case LT: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case GT: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case LOGNOT: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case AND: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case OR: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case XOR: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case SHIFTL: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case SHIFTR: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case IDENT: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case INT: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  case REAL: _pos--; _lexeme.erase( _lexeme.length()-1 ); break;
  default: ;
  }

  _last_token = -state;

  return -state;
}

bool Lexical::getEndfile(){
  
  return _ins.eof();
}

bool Lexical::openFile(){

  _ins.open( _filename.c_str() );
  if( !_ins.fail() )
    return true;

  return false;
}

bool Lexical::closeFile(){

  _ins.close();
  if( !_ins.fail() )
    return true;
  
  return false;
}
