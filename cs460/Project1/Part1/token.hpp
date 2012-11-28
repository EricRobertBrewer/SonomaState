/*
token.hpp
Eric Brewer
10/19/10
Watts
CS460
Token enumerated type - 
*/

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

enum TOKEN{ ERROR = 0,
	    PL, MIN, MULT, DIV, MOD,
	    PLPL, MINMIN, EQ, PLEQ, MINEQ,
	    MULTEQ, DIVEQ, MODEQ, SHIFTLEQ, SHIFTREQ,
	    ANDEQ, OREQ, XOREQ, EQEQ, NOTEQ,
	    LT, GT, LTEQ, GTEQ, LOGAND,
	    LOGOR, LOGNOT, AND, OR, XOR,
	    SHIFTL, SHIFTR, ONESCOMP, QUESTION, COLON,
	    COMMA, LPAREN, RPAREN, SEMI, IDENT,
	    INT, REAL, ENDFILE };

// Associated array used to print out TOKEN's name.
// ie. tok_names[ MINMIN ] translates to "MINMIN."
static string tok_names[] = { "ERROR   ", 
			      "PL      ", "MIN     ", "MULT    ", "DIV     ", "MOD     ",
			      "PLPL    ", "MINMIN  ", "EQ      ", "PLEQ    ", "MINEQ   ",
			      "MULTEQ  ", "DIVEQ   ", "MODEQ   ", "SHIFTLEQ", "SHIFTREQ",
			      "ANDEQ   ", "OREQ    ", "XOREQ   ", "EQEQ    ", "NOTEQ   ",
			      "LT      ", "GT      ", "LTEQ    ", "GTEQ    ", "LOGAND  ",
			      "LOGOR   ", "LOGNOT  ", "AND     ", "OR      ", "XOR     ",
			      "SHIFTL  ", "SHIFTR  ", "ONESCOMP", "QUESTION", "COLON   ",
			      "COMMA   ", "LPAREN  ", "RPAREN  ", "SEMI    ", "IDENT   ",
			      "INT     ", "REAL    ", "ENDFILE " };

// Holds the last lexeme read by getToken.
static string lexeme = "";

int getToken( istream &ins );
string getLexeme();
void reportError( string message );

#endif
