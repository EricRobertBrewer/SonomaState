/*
wProcess.cpp
Eric Brewer
10/26/10
Kooshesh
CS450 - Operating Systems
Chat Program: Writer Process -
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
using namespace std;
#include <string.h>
#include <pthread.h>

#define SERVER_PORT_ID        6300
//#define CLIENT_PORT_ID        6312
#define PORT_NUMBER_LEN          4
#define CLIENT_NAME_LEN         16
#define NAME_NOT_AVAILABLE       0
#define NAME_AVAILABLE           1
#define COMMAND_LEN              4

int readN( int sd, char *ptr, int size );
int writeN( int sd, char *ptr, int size );

int main( int argc, char *argv[] ){
  
  int sockid, newsockid, name_ok, n, msgsize = 0;
  char username[ CLIENT_NAME_LEN + 1 ];
  string command = "writ", msg;
  struct sockaddr_in my_addr, server_addr;

  if( argc != 4 ){
    cout << "wProcess: Incorrect number of arguments.\n";
    cout << "wProcess:  Usage: " << argv[0] << " <IP-address> <port number> <username>\n";
    exit( 1 );
  }

  if( strlen( argv[2] ) > PORT_NUMBER_LEN ){
    cout << "wProcess: Port number must be 4 digits or less.\n";
    exit( 2 );
  }

  if( strlen( argv[3] ) > CLIENT_NAME_LEN ){
    cout << "wProcess: Desired username must be 16 characters or less.\n";
    exit( 3 );
  }
  
  cout << "wProcess: Creating a socket...\n";
  if( ( sockid = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 ){
    cout << "wProcess: Couldn\'t create a socket.\n";
    exit( 4 );
  }
  
  cout << "wProcess: Binding my socket...\n";
  bzero( ( char * ) &my_addr, sizeof( my_addr ) );
  my_addr.sin_family = AF_INET;
  my_addr.sin_addr.s_addr = htonl( INADDR_ANY );
  my_addr.sin_port = htons( atoi( argv[2] )/*CLIENT_PORT_ID*/ );
  if( bind( sockid, ( struct sockaddr * ) &my_addr, sizeof( my_addr ) ) < 0 ){
    cout << "wProcess: Couldn\'t bind my socket.\n";
    exit( 5 );
  }
  
  cout << "wProcess: Connecting to server\'s socket...\n";
  bzero( ( char * ) &server_addr, sizeof( server_addr ) );
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr( argv[1] );
  server_addr.sin_port = htons( SERVER_PORT_ID );
  if( connect( sockid, ( struct sockaddr * ) &server_addr, sizeof( server_addr ) ) < 0 ){
    cout << "wProcess: Couldn\'t connect to server\'s socket.\n";
    exit( 6 );
  }

  // We have a connection.
  if( ( writeN( sockid, ( char * ) command.c_str(), COMMAND_LEN ) ) < 0 ){
    cout << "wProcess: Write error.\n";
    exit( 7 );
  }
  
  strcpy( username, argv[3] );
  if( ( writeN( sockid, username, CLIENT_NAME_LEN ) ) < 0 ){
    cout << "wProcess: Write error.\n";
    exit( 8 );
  }

  if( ( readN( sockid, ( char * ) &name_ok, sizeof( name_ok ) ) ) < 0 ){
    cout << "wProcess: Read error.\n";
    exit( 9 );
  }
  name_ok = ntohs( name_ok );
  if( name_ok == NAME_NOT_AVAILABLE ){
    cout << "wProcess: Username not found on server.\n";
    exit( 10 );
  }
  else
    cout << "wProcess: Username found.\n";

  // keep writing!!!
  // first, send the size of the outgoing message
  while( ( writeN( sockid, ( char * ) &msgsize, sizeof( msgsize ) ) ) > 0 ){

    // then, send the message
    if( ( n = writeN( sockid, ( char * ) msg.c_str(), msgsize ) ) < 0 ){
      cout << "wProcess: Write error.\n";
      exit( 11 );
    }
    getline( cin, msg );
    msgsize = msg.length();
    msg[ msgsize ] = '\0';
  }

}

int readN( int sd, char *ptr, int size ){
  int no_left, no_read;
  
  no_left = size;
  while( no_left > 0 ){
    no_read = read( sd, ptr, no_left );
    if( no_read < 0 )
      return( no_read );
    if( no_read == 0 )
      break;
    no_left -= no_read;
    ptr += no_read;
  }
  return( size - no_left );
}

int writeN( int sd, char *ptr, int size ){
  int no_left, no_written;

  no_left = size;
  while( no_left > 0 ){
    no_written = write( sd, ptr, no_left );
    if( no_written <= 0 )
      return( no_written );
    no_left -= no_written;
    ptr += no_written;
  }
  return( size - no_left );
}
