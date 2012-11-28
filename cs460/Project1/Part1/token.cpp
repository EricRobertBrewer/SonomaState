/*
token.cpp
Eric Brewer
10/20/10
Watts
CS460
Token enumerated type implemention - 
*/

#include "token.hpp"
#include "stateTable.hpp"

int getToken( istream &ins ){

  static string text = " ";
  static int pos = 0;
  lexeme = "";
  static int lineNo = 0;

  // Bypassing white space, marches along the file, one line at a time
  while( isspace( text[pos] ) ){
    pos++;
    if( pos >= text.length() ){

      getline( ins, text );
      lineNo++;
      cout << "[" << lineNo << "]  " << text << endl;
      if( ins.eof() )
	return ENDFILE;
      if( ins.fail() )
	return ERROR;
      text += " ";
      pos = 0;
    }
  }

  // Starting in state 1, use the state table and the received character to determine 
  //  the next state.
  int state = 1;
  while( state > 0 ){
    int a;
    // March 'a' along our alphabet until we fall off or until we hit the character we 
    //  are looking at.
    for( a = 0; a < SPYING_CHARACTER && alphabet[a] != text[pos]; a++ );
    state = table[a][state];
    lexeme += text[pos];
    pos++;
  }

  // In the cases where we have to look one character beyond to know that our lexeme has 
  //  finished, we must put back that last taken character.
  switch( -state ){
  case PL: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case MIN: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case MULT: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case DIV: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case MOD: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case EQ: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case LT: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case GT: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case LOGNOT: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case AND: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case OR: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case XOR: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case SHIFTL: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case SHIFTR: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case IDENT: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case INT: pos--; lexeme.erase( lexeme.length()-1 ); break;
  case REAL: pos--; lexeme.erase( lexeme.length()-1 ); break;
  default: ;
  }

  return -state;
}

string getLexeme(){

  return lexeme;
}

void reportError( string message ){

  cout << message << endl;
}
