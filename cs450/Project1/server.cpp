/*
server.cpp
Eric Brewer
10/25/10
Kooshesh
CS450 - Operating Systems
Chat Program: Server - 
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
#include <string>
#include <pthread.h>
#include "Client.hpp"
#include "ChatRoom.hpp"
#include "ClientCollection.hpp"
#include "ChatRoomCollection.hpp"

#define MY_PORT_ID            6300
#define LISTENQ                  5
#define CLIENT_NAME_LEN         16
#define NAME_NOT_AVAILABLE       0
#define NAME_AVAILABLE           1
#define COMMAND_NOT_ACCEPTED     0
#define COMMAND_ACCEPTED         1
#define COMMAND_WRITE_BACK       2
#define COMMAND_LEN              4
#define MAXLINE                234

void *commandThread( void *sID );
void *readerThread( void *sID );
void *writerThread( void *sID );
// The two below trigger a ChatRoom's posting threads.
void dispatch( ChatRoom *chatRoom );
void *messenger( void *v );
int readN( int sd, char *ptr, int size );
int writeN( int sd, char *ptr, int size );

ClientCollection allClients;
ChatRoomCollection allChatRooms;
ChatRoom *defaultChatRoom = new ChatRoom( "Default" );
pthread_mutex_t accept_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t command_mutex = PTHREAD_MUTEX_INITIALIZER;

int main(){
  int sSockID, cSockID, n;
  pthread_t tid;
  struct sockaddr_in my_addr, client_addr;
  socklen_t clilen = sizeof( client_addr );
  char ipaddr[ MAXLINE ];
  char command[ COMMAND_LEN + 1 ];

  cout << "server: Creating a socket...\n";
  if( ( sSockID = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 ){
    cout << "Couldn\'t create a socket.\n";
    exit( 1 );
  }

  cout << "server: Binding my socket...\n";
  bzero( ( char * ) &my_addr, sizeof( my_addr ) );
  my_addr.sin_family = AF_INET;
  my_addr.sin_addr.s_addr = htonl( INADDR_ANY );
  my_addr.sin_port = htons( MY_PORT_ID );
  if( bind( sSockID, ( struct sockaddr * ) &my_addr, sizeof( my_addr ) ) < 0 ){
    cout << "server: Couldn\'t bind my socket.\n";
    exit( 2 );
  }

  cout << "server: Listening at my socket...\n";
  if( listen( sSockID, LISTENQ ) < 0 ){
    cout << "server: Listen error.\n";
    exit( 3 );
  }

  // the heart:  
  allChatRooms.addChatRoom( defaultChatRoom );
  dispatch( defaultChatRoom );

  for( ; ; ){

    cout << "server: Accepting requests...\n";
    pthread_mutex_lock( &accept_mutex );
    if( ( cSockID = accept( sSockID, ( struct sockaddr * ) &client_addr, &clilen ) ) < 0 ){
      cout << "server: Accept error.\n";
      exit( 4 );
    }

    cout << "server: -- Connection from " 
 	 << inet_ntop( AF_INET, &client_addr.sin_addr, ipaddr, sizeof( ipaddr ) )
	 << ", port " 
	 << ntohs( client_addr.sin_port ) << ".\n";

    if( ( n = readN( cSockID, command, COMMAND_LEN ) ) < 0 ){
      cout << "server: Read error.\n";
      exit( 5 );
    }
    // Decipher which process was launched and fire the appropriate thread
    command[ COMMAND_LEN ] = '\0';
    if( !strcmp( command, "join" ) ){
      cout << "server: Creating command thread...\n";
      pthread_create( &tid, NULL, commandThread, &cSockID );
    }
    else if( !strcmp( command, "read" ) ){
      cout << "server: Creating reader thread...\n";
      pthread_create( &tid, NULL, readerThread, &cSockID ); 
    }
    else if( !strcmp( command, "writ" ) ){
      cout << "server: Creating writer thread...\n";
      pthread_create( &tid, NULL, writerThread, &cSockID ); 
    }
    
  }

}

void *commandThread( void *sID ){
  int sockID = *( reinterpret_cast<int *>( sID ) );
  pthread_mutex_unlock( &accept_mutex );

  int name_ok, n, cmdsize = COMMAND_LEN, cmdstatus, wbsize;
  bool valid, write_back;
  string clientName, comstr, comhead = "", comarg = "", wbmessage;
  char username[ CLIENT_NAME_LEN + 1 ];
  char buff[ MAXLINE ];
  Client *client;

  cout << "cThread(" << pthread_self() << "): Reading username...\n";
  if( ( readN( sockID, username, CLIENT_NAME_LEN ) ) < 0 ){
    cout << "cThread(" << pthread_self() << "): Read error.\n";
    exit( 6 );
  }

  clientName = username;
  if( allClients.exists( clientName ) ){
    name_ok = NAME_NOT_AVAILABLE;
    name_ok = htons( name_ok );
    if( ( writeN( sockID, ( char * ) &name_ok, sizeof( name_ok ) ) ) < 0 ){
      cout << "cThread(" << pthread_self() << "): Write error.\n";
      exit( 7 );
    }
    pthread_exit( NULL );
  }
  
  name_ok = NAME_AVAILABLE;
  name_ok = htons( name_ok );
  if( ( writeN( sockID, ( char * ) &name_ok, sizeof( name_ok ) ) ) < 0 ){
    cout << "cThread(" << pthread_self() << "): Write error.\n";
    exit( 8 );
  }

  client = new Client( clientName, defaultChatRoom );
  defaultChatRoom->addClient( client );
  client->setCommandSockDesc( sockID );
  allClients.addClient( client );

  while( !client->isActive() );
 
  memset( buff, '\0', MAXLINE );

  // first, read the size of the command
  while( ( readN( sockID, ( char * ) &cmdsize, sizeof( cmdsize ) ) ) > 0 ){

    // then, read the command
    if( ( n = readN( sockID, buff, cmdsize ) ) < 0 ){
      cout << "cThread(" << pthread_self() << "): Read error.\n";
      exit( 9 );
    }
    comstr = buff;
    cout << "cThread(" << pthread_self() << "): " << comstr << "\n";
    
    // In order to keep the internals consistent across clients, we lock this region
    pthread_mutex_lock( &command_mutex );

    // first pass - see if the command has the right number of characters
    valid = true;
    write_back = false;
    if( comstr.length() > 3 ){
      for( int i = 0; i < 4; i++ )
	comhead += comstr[i];
    }
    else
      valid = false;
    if( comhead != "bye." && comhead != "shut" && comhead != "lscr" && comhead != "lssu" && comhead != "myde" )
      if( comstr.length() > 5 )
	for( int j = 5; j < comstr.length(); j++ )
	  comarg += comstr[j];
      else
	valid = false;
    
    // second pass - interpret the command
    if( valid ){
      
      // "bye." - client wishes to exit the server
      if( comhead == "bye." ){
	allChatRooms.wipeClient( client->getID() );
	allClients.deleteClient( client->getID() );
	client->closeReader();
	client->closeWriter();
      }
      // "crea" - CREAte a new chatroom
      else if( comhead == "crea" ){
	ChatRoom *newRoom = new ChatRoom( comarg );
	if( !allChatRooms.addChatRoom( newRoom ) )
	  valid = false;
	else
	  dispatch( newRoom );
      }
      // "subs" - SUBScribe to an existing chatroom
      else if( comhead == "subs" ){
	ChatRoom *newRoom;
	if( newRoom = allChatRooms.exists( comarg ) )
	  if( !newRoom->addClient( client ) )
	    valid = false;
	  else;
	else
	  valid = false;
      }
      // "unsu" - UNSUbscribe from a given chatroom
      else if( comhead == "unsu" ){
	ChatRoom *newRoom;
	if( newRoom = allChatRooms.exists( comarg ) )
	  if( newRoom->removeClient( client->getID() ) )
	    if( !newRoom->numClients() && newRoom->getRoomName() != "Default" ){
	      allChatRooms.deleteChatRoom( comarg );
	      // Below should trigger the clean-up of the ChatRoom's consumer threads
	      newRoom = NULL;
	    }
	    else;
	  else 
	    valid = false;
	else
	  valid = false;
      }
      // "shut" - SHUT the server down
      else if( comhead == "shut" ){

      }
      // "myde" - displays the client's default chatroom
      else if( comhead == "myde" ){
	wbmessage = "(None)\n";
	if( client->getDefaultChatRoom() ){
	  wbmessage = client->getDefaultChatRoom()->getRoomName();
	  wbmessage += '\n';
	}
	write_back = true;
      }
      // "defa" - change the client's DEFAult chatroom; this is where the client's messages are sent
      else if( comhead == "defa" ){
	ChatRoom *newRoom;
	if( newRoom = allChatRooms.exists( comarg ) ){
	  client->setDefaultChatRoom( newRoom );
	  newRoom->addClient( client );
	}
	else
	  valid = false;
      }
      // "lscr" - provide a LIst of all existing ChatRooms
      else if( comhead == "lscr" ){
	wbmessage = allChatRooms.lscr();
	write_back = true;
      }
      // "lssu" - provide a LIst of chatrooms to which this client has SUbscribed 
      else if( comhead == "lssu" ){
	wbmessage = allChatRooms.lssu( client->getID() );
	write_back = true;
      }
      else
	valid = false;
    }

    if( valid )
      if( write_back )
	cmdstatus = COMMAND_WRITE_BACK;
      else
	cmdstatus = COMMAND_ACCEPTED;
    else
      cmdstatus = COMMAND_NOT_ACCEPTED;

    if( ( writeN( sockID, ( char * ) &cmdstatus, sizeof( cmdstatus ) ) ) < 0 ){
      cout << "cThread(" << pthread_self() << "): Write error.\n";
      exit( 10 );
    }
    if( cmdstatus == COMMAND_WRITE_BACK ){
      wbsize = wbmessage.length();
      if( ( writeN( sockID, ( char * ) &wbsize, sizeof( wbsize ) ) ) < 0 ){
	cout << "cThread(" << pthread_self() << "): Write error.\n";
	exit( 11 );
      }
      if( ( writeN( sockID, ( char * ) wbmessage.c_str(), wbsize ) ) < 0 ){
	cout << "cThread(" << pthread_self() << "): Write error.\n";
	exit( 12 );
      }
    }
    pthread_mutex_unlock( &command_mutex );

    comhead = "";
    comarg = "";
    wbmessage = "";
    memset( buff, '\0', MAXLINE );    
    
  }
  // clean up!
  pthread_exit( NULL );
}

// client's reader thread. The server writes to its socket!
void *readerThread( void *sID ){
  int sockID = *( reinterpret_cast<int *>( sID ) );
  pthread_mutex_unlock( &accept_mutex );

  int name_ok, n, msgsize = 0;
  string clientName, msg;
  char username[ CLIENT_NAME_LEN + 1 ];
  Client *client;

  cout << "rThread(" << pthread_self() << "): Reading username...\n";
  if( ( readN( sockID, username, CLIENT_NAME_LEN ) ) < 0 ){
    cout << "rThread(" << pthread_self() << "): Read error.\n";
    exit( 10 );
  }

  clientName = username;
  if( ( client = allClients.exists( clientName ) ) == NULL ){
    name_ok = NAME_NOT_AVAILABLE;
    name_ok = htons( name_ok );
    if( ( writeN( sockID, ( char * ) &name_ok, sizeof( name_ok ) ) ) < 0 ){
      cout << "rThread(" << pthread_self() << "): Write error.\n";
      exit( 11 );
    }
    pthread_exit( NULL );
  }

  name_ok = NAME_AVAILABLE;
  name_ok = htons( name_ok );
  if( ( writeN( sockID, ( char * ) &name_ok, sizeof( name_ok ) ) ) < 0 ){
    cout << "rThread(" << pthread_self() << "): Write error.\n";
    exit( 12 );
  }

  client->setReaderSockDesc( sockID );
  
  while( !client->isActive() );

  // send the size of the outgoing message
  while( ( writeN( sockID, ( char * ) &msgsize, sizeof( msgsize ) ) ) > 0 ){

    // send the message to the client
    if( ( n = writeN( sockID, ( char * ) msg.c_str(), msgsize ) ) < 0 ){
      cout << "rThread(" << pthread_self() << "): Write error.\n";
      exit( 13 );
    }
    msg = client->readChatMessage();
    msgsize = msg.length();
    msg[ msgsize ] = '\0';
  }

  client->closeReader();
  pthread_exit( NULL );
}

// client's writer thread. The server reads from it.
void *writerThread( void *sID ){
  int sockID = *( reinterpret_cast<int *>( sID ) );
  pthread_mutex_unlock( &accept_mutex );
  
  int name_ok, n, msgsize = 0;
  string clientName, msg, nametag, fullmsg;
  char username[ CLIENT_NAME_LEN + 1 ];
  char buff[ MAXLINE ];
  Client *client;

  cout << "wThread(" << pthread_self() << "): Reading username...\n";
  if( ( readN( sockID, username, CLIENT_NAME_LEN ) ) < 0 ){
    cout << "wThread(" << pthread_self() << "): Read error.\n";
    exit( 14 );
  }

  clientName = username;
  if( ( client = allClients.exists( clientName ) ) == NULL ){
    name_ok = NAME_NOT_AVAILABLE;
    name_ok = htons( name_ok );
    if( ( writeN( sockID, ( char * ) &name_ok, sizeof( name_ok ) ) ) < 0 ){
      cout << "wThread(" << pthread_self() << "): Write error.\n";
      exit( 15 );
    }
    pthread_exit( NULL );
  }

  name_ok = NAME_AVAILABLE;
  name_ok = htons( name_ok );
  if( ( writeN( sockID, ( char * ) &name_ok, sizeof( name_ok ) ) ) < 0 ){
    cout << "wThread(" << pthread_self() << "): Write error.\n";
    exit( 16 );
  }

  client->setWriterSockDesc( sockID );
  nametag = "[";
  nametag += clientName;
  nametag += "]";
  for( int i = 0; i < ( CLIENT_NAME_LEN - clientName.length() ); i++ )
    nametag += " ";
  nametag += "> ";

  while( !client->isActive() );

  memset( buff, '\0', MAXLINE );
  // get the size of the incoming message
  while( ( readN( sockID, ( char * ) &msgsize, sizeof( msgsize ) ) ) > 0 ){

    // read msg from the client's writer process
    if( ( n = readN( sockID, buff, msgsize ) ) < 0 ){
      cout << "wThread(" << pthread_self() << "): Read error.\n";
      exit( 17 );
    }  
    msg = buff;
    fullmsg = nametag;
    fullmsg += msg;
    client->postMessageToDefaultChatRoom( fullmsg );
    memset( buff, '\0', MAXLINE );    
  }

  client->closeWriter();
  pthread_exit( NULL );
}

void dispatch( ChatRoom *chatRoom ){
  pthread_t tid;

  pthread_create( &tid, NULL, messenger, chatRoom );
  pthread_create( &tid, NULL, messenger, chatRoom );
  pthread_create( &tid, NULL, messenger, chatRoom );
  pthread_create( &tid, NULL, messenger, chatRoom );
}

void *messenger( void *v ){
  ChatRoom *cr = reinterpret_cast<ChatRoom *>( v );

  while( cr )
    cr->distributeMessages();

  pthread_exit( NULL );
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
