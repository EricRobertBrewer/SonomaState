/*
main.cpp
Eric Brewer
12/12/10
Watts
CS460 - Programming Languages
Main function - 
*/

#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>

#include "Syntactic.hpp"
#include "Symbol.hpp"
#include "token.hpp"

#define MAIN_DEBUG 1
#define main_debug if( MAIN_DEBUG ) cout

int evaluate( int starti, Syntactic& syn );
Symbol* findInTable( string name );
void operation();

vector< Symbol* > operators;
vector< Symbol* > operands;
vector< Symbol* > table;

int main( int argc, char* argv[] ){
  
  if( argc != 2 ){
    cout << "Error: Usage:  " << argv[0] << " <filename>" << endl;
    exit( 1 );
  }

  Syntactic syntactic( argv[1] );
  syntactic.beginParse();

  cout << "Found " << syntactic.getErrors() << " errors." << endl;

  if( !syntactic.getErrors() ){
    evaluate( 0, syntactic );
    for( int i = 0; i < table.size(); i++ )
      cout << table[i]->getName() << "\t" << table[i]->value() << endl;
  }
  else
    cout << "Fix errors." << endl;

  return 0;
}

int evaluate( int starti, Syntactic& syn ){

  int numbinops = 0;
  int index = starti;
  Symbol* temp;

  while( index <= syn.tokens()->size() && syn.tokens()[0][index] != ENDFILE && syn.tokens()[0][index] != ERROR ){

    // Phase 1: operand or left-parenthesis
    main_debug << "index: " << index << endl;
    main_debug << "syn.tokens()[0][index]: " << syn.tokens()[0][index] << endl;
    main_debug << "syn.lexemes()[0][index]: " << syn.lexemes()[0][index] << endl;
    if( syn.tokens()[0][index] == LPAREN ){
      index++;
      index = evaluate( index, syn );
    }
    else if( syn.tokens()[0][index] == IDENT ){
      if( temp = findInTable( syn.lexemes()[0][index] ) )
      operands.push_back( temp );
      else{
	operands.push_back( new Identifier( syn.lexemes()[0][index], new Literal() ) );
	table.push_back( new Identifier( syn.lexemes()[0][index], new Literal() ) );
      }
      index++;
    }
    else if( syn.tokens()[0][index] == INT ){
      operands.push_back( new Integer( syn.lexemes()[0][index] ) );
      index++;
    }
    else if( syn.tokens()[0][index] == REAL ){
      operands.push_back( new Real( syn.lexemes()[0][index] ) );
      index++;
    }
    else{
    cout << "Unexplored phase1: " << syn.lexemes()[0][index] << " index: " << index << endl;
    exit( 2 );
    }
    
    // Phase 2: right-parenthesis, semi-colon or binary operator
    main_debug << "index: " << index << endl;
    main_debug << "syn.tokens()[0][index]: " << syn.tokens()[0][index] << endl;
    main_debug << "syn.lexemes()[0][index]: " << syn.lexemes()[0][index] << endl;
    if( syn.tokens()[0][index] == RPAREN ){
      for( numbinops; numbinops; numbinops-- )
	operation();
      return (index + 1);
    }
    else if( syn.tokens()[0][index] == SEMI ){
      for( numbinops; numbinops; numbinops-- )
	operation();
      operands.pop_back();
      index++;
    }
    else if( syn.tokens()[0][index] == PL ||
	     syn.tokens()[0][index] == MIN ||
	     syn.tokens()[0][index] == MULT ||
	     syn.tokens()[0][index] == DIV ||
	     syn.tokens()[0][index] == MOD ||
	     syn.tokens()[0][index] == EQ ||
	     syn.tokens()[0][index] == PLEQ ||
	     syn.tokens()[0][index] == MINEQ ||
	     syn.tokens()[0][index] == MULTEQ ||
	     syn.tokens()[0][index] == DIVEQ ||
	     syn.tokens()[0][index] == MODEQ ){
      while( numbinops && precedence[syn.tokens()[0][index]] > precedence[operators.back()->getTokenID()] ){
	operation();
	numbinops--;
      }
      while( numbinops && precedence[syn.tokens()[0][index]] == precedence[operators.back()->getTokenID()] && !lefttoright[syn.tokens()[0][index]] ){
	operation();
	numbinops--;
      }
      operators.push_back( new Operator( syn.lexemes()[0][index], syn.tokens()[0][index] ) );
      numbinops++;
      index++;
    }
    else{
      cout << "Unexplored phase2: " << syn.lexemes()[0][index] << " index: " << index << endl;
      exit( 3 );
    }

  }

}

Symbol* findInTable( string name ){

  for( int i = 0; i < table.size(); i++ )
    if( table[i]->getName() == name )
      return table[i];

  return NULL;
}

void operation(){

  Symbol* temp;
  bool isfloat;

  isfloat = operands.back()->isFloat() || operands[operands.size()-2]->isFloat();
  if( operators.back()->getTokenID() == PL ){
    if( isfloat )
      temp = new Real( operands.back()->value() + operands[operands.size()-2]->value() );
    else
      temp = new Integer( operands.back()->value() + operands[operands.size()-2]->value() ); 
    operators.pop_back();
    operands.pop_back();
    operands.pop_back();
    operands.push_back( temp );
  }
  else if( operators.back()->getTokenID() == MIN ){
    if( isfloat )
      temp = new Real( operands[operands.size()-2]->value() - operands.back()->value() );
    else
      temp = new Integer( operands[operands.size()-2]->value() - operands.back()->value() );
    operators.pop_back();
    operands.pop_back();
    operands.pop_back();
    operands.push_back( temp );
  }
  else if( operators.back()->getTokenID() == MULT ){
    if( isfloat )
      temp = new Real( operands[operands.size()-2]->value() * operands.back()->value() );
    else
      temp = new Integer( operands[operands.size()-2]->value() * operands.back()->value() );
    operators.pop_back();
    operands.pop_back();
    operands.pop_back();
    operands.push_back( temp );
  }
  else if( operators.back()->getTokenID() == DIV ){
    if( isfloat )
      temp = new Real( operands[operands.size()-2]->value() / operands.back()->value() );
    else
      temp = new Integer( operands[operands.size()-2]->value() / operands.back()->value() );
    operators.pop_back();
    operands.pop_back();
    operands.pop_back();
    operands.push_back( temp );
  }
  else if( operators.back()->getTokenID() == MOD ){
    if( isfloat ){
      cout << "Error: MOD using a float value." << endl;
      exit( 4 );
    }
    else
      temp = new Integer( operands[operands.size()-2]->value() % operands.back()->value() );
    operators.pop_back();
    operands.pop_back();
    operands.pop_back();
    operands.push_back( temp );
  }
  else if( operators.back()->getTokenID() == EQ ){
    if( !( temp = findInTable( operands[operands.size()-2]->getName() ) ) ){
      cout << "Bad assignment in EQ." << endl;
      exit( 7 );
    }
    if( isfloat )
      temp->setValue( new Real( operands.back()->value() ) );
    else
      temp->setValue( new Integer( operands.back()->value() ) );
    temp->setFloat( isfloat );
    operators.pop_back();
    operands.pop_back();
    operands.pop_back();
    operands.push_back( temp );
  }
  else if( operators.back()->getTokenID() == PLEQ ){
    if( !( temp = findInTable( operands[operands.size()-2]->getName() ) ) ){
      cout << "Bad assignment in PLEQ." << endl;
      exit( 8 );
    }
    if( isfloat )
      temp->setValue( new Real( operands[operands.size()-2]->value() + operands.back()->value() ) );
    else
      temp->setValue( new Integer( operands[operands.size()-2]->value() + operands.back()->value() ) );
    temp->setFloat( isfloat );
    operators.pop_back();
    operands.pop_back();
    operands.pop_back();
    operands.push_back( temp );
  }
  else if( operators.back()->getTokenID() == MINEQ ){
    if( !( temp = findInTable( operands[operands.size()-2]->getName() ) ) ){
      cout << "Bad assignment in MINEQ." << endl;
      exit( 9 );
    }
    if( isfloat )
      temp->setValue( new Real( operands[operands.size()-2]->value() - operands.back()->value() ) );
    else
      temp->setValue( new Integer( operands[operands.size()-2]->value() - operands.back()->value() ) );
    temp->setFloat( isfloat );
    operators.pop_back();
    operands.pop_back();
    operands.pop_back();
    operands.push_back( temp );
  }
  else if( operators.back()->getTokenID() == MULTEQ ){
    if( !( temp = findInTable( operands[operands.size()-2]->getName() ) ) ){
      cout << "Bad assignment in MULTEQ." << endl;
      exit( 10 );
    }
    if( isfloat )
      temp->setValue( new Real( operands[operands.size()-2]->value() * operands.back()->value() ) );
    else
      temp->setValue( new Integer( operands[operands.size()-2]->value() * operands.back()->value() ) );
    temp->setFloat( isfloat );
    operators.pop_back();
    operands.pop_back();
    operands.pop_back();
    operands.push_back( temp );
  }
  else if( operators.back()->getTokenID() == DIVEQ ){
    if( !( temp = findInTable( operands[operands.size()-2]->getName() ) ) ){
      cout << "Bad assignment in DIVEQ." << endl;
      exit( 11 );
    }
    if( isfloat )
      temp->setValue( new Real( operands[operands.size()-2]->value() / operands.back()->value() ) );
    else
      temp->setValue( new Integer( operands[operands.size()-2]->value() / operands.back()->value() ) );
    temp->setFloat( isfloat );
    operators.pop_back();
    operands.pop_back();
    operands.pop_back();
    operands.push_back( temp );
  }
  else if( operators.back()->getTokenID() == MODEQ ){
    if( !( temp = findInTable( operands[operands.size()-2]->getName() ) ) ){
      cout << "Bad assignment in MODEQ." << endl;
      exit( 12 );
    }
    if( isfloat ){
      cout << "Error: MOD using a float value." << endl;
      exit( 5 );
    }
    else
      temp->setValue( new Integer( operands[operands.size()-2]->value() % operands.back()->value() ) );
    operators.pop_back();
    operands.pop_back();
    operands.pop_back();
    operands.push_back( temp );
  }
  else{
    cout << "Unexplored operation." << endl;
    exit( 6 );
  }
}
