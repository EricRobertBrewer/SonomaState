2/*
server.c
Eric Brewer
2/14/11
Lyle
CS365 - Computer Networking
Server side - 
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define SERVER_PORT 6300
#define MAX_PENDING 5
#define MAX_LINE 256

int main( int argc, char* argv[] ){

  struct sockaddr_in sin; 
  char buf[MAX_LINE];
  int s, new_s;
  socklen_t len = sizeof( sin );

  // Address struct
  bzero( (char*) &sin, sizeof( sin ) );
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = INADDR_ANY;
  sin.sin_port = htons( SERVER_PORT );

  // Open socket
  if( ( s = socket( PF_INET, SOCK_STREAM, 0 ) ) < 0 ){
    perror( "simplex-talk: socket" );
    exit( 1 );
  }

  // Bind
  if( ( bind( s, (struct sockaddr*) &sin, sizeof( sin ) ) ) < 0 ){
    perror( "simplex-talk: bind" );
    exit( 2 );
  }

  listen( s, MAX_PENDING );

  // Wait for connection and print
  while( 1 ){
    if( ( new_s = accept( s, (struct sockaddr*) &sin, &len ) ) < 0 ){
      perror( "simplex-talk: accept" );
      exit( 3 );
    }
    
    while( len = recv( new_s, buf, sizeof( buf ), 0 ) )
      fputs( buf, stdout );
    
    close( new_s );
  }

  return 0;
}
