/*
shell.cpp
Eric Brewer
12/6/10
Kooshesh
CS450 - Operating Systems
Shell program; main function - 
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <fcntl.h>

#include "Parser.hpp"

#define DEBUG 0
#define debug if( DEBUG ) cout

#define MAX_LINE 1024
#define MAX_PIPES 15
#define MAX_LEXEMES 271
#define MAX_COMMANDS 16
#define MAX_ARGS 16
#define MAX_STR_LENGTH 256
enum DIRECTION{ READ = 0, WRITE };

int main( int argc, char *argv[] ){

  Parser parser;
  string line;
  string lexemes[MAX_LEXEMES];
  string commands[MAX_COMMANDS][MAX_ARGS];
  char*** c_commands = new char**[MAX_COMMANDS];
  for( int i = 0; i < MAX_COMMANDS; i++ ){
    c_commands[i] = new char*[MAX_ARGS];
    for( int j = 0; j < MAX_ARGS; j++ )
      c_commands[i][j] = new char[MAX_STR_LENGTH];
  }
  // Needed to prevent Seg. Faults after a c-string is set to NULL
  //  to appease execvp().
  char*** null_backup = new char**[MAX_COMMANDS];
  null_backup = c_commands;
  for( int i = 0; i < MAX_COMMANDS; i++ ){
    null_backup[i] = new char*[MAX_ARGS];
    null_backup[i] = c_commands[i];
    for( int j = 0; j < MAX_ARGS; j++ ){
      null_backup[i][j] = new char[MAX_STR_LENGTH];
      null_backup[i][j] = c_commands[i][j];
    }
  }
  int pipefds[MAX_PIPES][2];
  int num_pipes, lindex, num_commands, pindex;
  int num_args[MAX_COMMANDS];
  int redirect[2];

   while( true ){

    // Initialization
    num_pipes = 0;
    num_commands = 0;
    for( int i = 0; i < MAX_COMMANDS; i++ ) num_args[i] = 0;
    redirect[READ] = 0;
    redirect[WRITE] = 1;

    // Grab the entire line
    cout << "[SHELL]$ ";
    getline( cin, line );
    parser.setLine( line );

    // Throw each word of the line into lexemes[]. Count number of pipes
    for( lindex = 0; !parser.eol(); lindex++ ){
      if( ( lexemes[lindex] = parser.getNextLexeme() ) == "|" )
	num_pipes++;
    }

    // Debug
    debug << "lindex: " << lindex << endl;
    debug << "num_pipes: " << num_pipes << endl;

    // Create the 'string commands[][]' structure
    // For example:
    //   sort -n aFile | uniq -c | sort -nr
    // becomes:
    //       0     1     2  
    //   0  sort  -n    aFile
    //   1  uniq  -c
    //   2  sort  -nr
    for( int i = 0; i < lindex; i++ ){
      if( lexemes[i] == "|" ){
	num_commands++;
	num_args[num_commands] = 0;
      }
      else{
	commands[num_commands][num_args[num_commands]] = lexemes[i];
	num_args[num_commands]++;
      }
    }
    num_commands++;  

    // Copy C++ strings into associated c-strings in identical structure
    for( int i = 0; i < num_commands; i++ ){
      for( int j = 0; j < num_args[i]; j++ )
	strcpy( c_commands[i][j], commands[i][j].c_str() );
      // set to NULL because execvp takes an array of c-strings terminated by a null string
      // char*** null_backup has the original pointer saved
      c_commands[i][num_args[i]] = 0;
    }

    // More debug
    debug << "C++ strings: " << endl;
    for( int i = 0; i < num_commands; i++ ){
      for( int j = 0; j < num_args[i]; j++ ){
	debug << commands[i][j] << ' ';
      }
      debug << endl;
    }
    debug << "c-strings: " << endl;
    for( int i = 0; i < num_commands; i++ ){
      for( int j = 0; j < num_args[i]; j++ ){
	debug << c_commands[i][j] << ' ';
      }
      debug << endl;
    }

    // After we create the c_commands[][] structure, we can execute
    //pipefds[0][READ] = redirect[READ];
    //debug << "pipefds[0][READ]: " << pipefds[0][READ] << endl;
    for( pindex = 1; pindex <= num_pipes; pindex++ ){

      if( pindex != 1 )
	close( pipefds[pindex-1][WRITE] );

      pipe( pipefds[pindex] );
      debug << "c_commands[" << pindex-1 << "][0]: " << c_commands[pindex-1][0] << endl;
      debug << "pipefds[" << pindex << "][READ]: " << pipefds[pindex][READ] << endl;
      debug << "pipefds[" << pindex << "][WRITE]: " << pipefds[pindex][WRITE] << endl;

      // Child process
      if( fork() == 0 ){
	dup2( pipefds[pindex-1][READ], 0 );
	close( pipefds[pindex-1][READ] );
	dup2( pipefds[pindex][WRITE], 1 );
	close( pipefds[pindex][WRITE] );
	close( pipefds[pindex][READ] );
	execvp( c_commands[pindex-1][0], c_commands[pindex-1] );
      }

      if( pindex != 1 )
	close( pipefds[pindex-1][READ] );
    }

    // Once there are no more pipes, repeat
    //pipefds[num_pipes+1][WRITE] = redirect[WRITE];
    //debug << "pipefds[" << num_pipes+1 << "][WRITE]: " << pipefds[num_pipes+1][WRITE] << endl;

    if( pindex != 1 )
      close( pipefds[pindex-1][WRITE] );

    debug << "c_commands[" << pindex-1 << "][0]: " << c_commands[pindex-1][0] << endl;
    debug << "pipefds[" << pindex << "][READ]: " << pipefds[pindex][READ] << endl;
    debug << "pipefds[" << pindex << "][WRITE]: " << pipefds[pindex][WRITE] << endl;

    // Child process
    if( fork() == 0 ){
      dup2( pipefds[pindex-1][READ], 0 );
      close( pipefds[pindex-1][READ] );
      close( pipefds[pindex][READ] );
      execvp( c_commands[pindex-1][0], c_commands[pindex-1] );
    }

    if( pindex != 1 )
      close( pipefds[pindex-1][READ] );

    while( wait( NULL ) != -1 );

    // Restore those null c-strings used as last arguments to execvp
    for( int i = 0; i < num_commands; i++ )
      c_commands[i][num_args[i]] = null_backup[i][num_args[i]];

  }

  return 0;
}
