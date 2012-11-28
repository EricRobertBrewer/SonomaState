/*
client.c
Eric Brewer
2/14/11
Lyle
CS365 - Computer Networking
Client side - 
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
#define MAX_LINE 256

int main( int argc, char* argv[] ){

  struct hostent* hp;
  struct sockaddr_in sin;
  char* host;
  char buf[MAX_LINE];
  int s;
  int len;

  if( argc == 2 )
    host = argv[1];
  else{
    printf( stderr, "usage: simplex-talk host\n" );
    exit( 1 );
  }

  // Host to IP
  hp = gethostbyname( host );
  if( !hp ){
    fprintf( stderr, "simplex-talk: unknown host: %s\n", host );
    exit( 2 );
  }

  // Address struct
  bzero( (char*) &sin, sizeof( sin ) );
  sin.sin_family = AF_INET;
  bcopy( hp->h_addr, (char*) &sin.sin_addr, hp->h_length );
  sin.sin_port = htons( SERVER_PORT );

  // Open, active
  if( ( s = socket( PF_INET, SOCK_STREAM, 0 ) ) < 0 ){
    perror( "simplex-talk: socket" );
    exit( 3 );
  }

  // Connect
  if( connect( s, (struct sockaddr*) &sin, sizeof( sin ) ) < 0 ){
    perror( "simplex-talk: connect" );
    close( s );
  }

  // Loop, copying
  while( fgets( buf, sizeof( buf ), stdin ) ){
    buf[MAX_LINE-1] = '\0';
    len = strlen( buf ) + 1;
    send( s, buf, len, 0 );
  }

  return 0;
}
