#include "Scanner.hpp"

Scanner :: Scanner(){
  _fileName = "";
}

void Scanner :: open(){
  fin.open( _fileName.c_str(), ifstream::in );
}

void Scanner :: open( string file ){
  fin.open( file.c_str(), ifstream::in );
  _fileName = file;
}

Token Scanner :: getToken(){
  Token in_token;
  string candidate = "";
  char c = ' ';

  while( c == ' ' ){
    cout << 'a' << endl;
    c = fin.get();
    if( c == '#' ){
      c = ' ';
      skipCommentLine();
    }
  }

  candidate += c;
  
  if( candidate.compare(":") == 0 )
    in_token.isAColon() = true;
  else if( candidate.compare("\t") == 0 )
    in_token.isATab() = true;
  else if( candidate.compare("\n") == 0 )
    in_token.eol() = true;
  else if( !fin.good() )
    in_token.eof() = true;
  else{
    while( fin.good() && c != ' ' && c != '\t' && c != '\n' && c != ':' ){
      cout << 'b' << endl;
      candidate += c;
      c = fin.get();
    }
    fin.putback(c);
    
  }
  
  in_token.name() = candidate;

  // badtoken check (?)

  return in_token;
}

string Scanner :: readCommand(){
  string command = "";
  char c = ' ';

  while( c != '\n' ){
    c = fin.get();
    // check fin.good()
    command += c;
  }

  return command;
}

void Scanner :: skipCommentLine(){
  char d = ' ';

  do{
    fin.get(d);
  } while( d != '\n' );

}
