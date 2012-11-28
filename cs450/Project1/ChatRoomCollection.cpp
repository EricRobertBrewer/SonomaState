/*
ChatRoomCollection.cpp
Eric Brewer
10/26/10
Kooshesh
CS450 - Operating Systems
Chat Program: ChatRoomCollection class implementation - 
*/

#include "ChatRoomCollection.hpp"
#include "ChatRoom.hpp"

ChatRoomCollection::ChatRoomCollection(){

  _rooms.clear();
}

bool ChatRoomCollection::addChatRoom( ChatRoom *chatRoom ){
  bool found = false;

  for( int i = 0; i < _rooms.size() && !found; i++ )
    if( chatRoom->getRoomName() == _rooms[i]->getRoomName() )
      found = true;
    
  if( !found )
    _rooms.push_back( chatRoom );

  return !found;
}

bool ChatRoomCollection::deleteChatRoom( string chatRoomName ){
  bool found = false;

  int i;
  for( i = 0; i < _rooms.size() && !found; i++ )
    if( chatRoomName == _rooms[i]->getRoomName() )
      found = true;

  if( found ){
    _rooms[i] = _rooms.back();
    _rooms.pop_back();
  }
  
  return found;
}

ChatRoom *ChatRoomCollection::exists( string cRName ){

  for( int i = 0; i < _rooms.size(); i++ )
    if( cRName == _rooms[i]->getRoomName() )
      return _rooms[i];

  return NULL;
}

void ChatRoomCollection::wipeClient( string cliName ){
  
  for( int i = 0; i < _rooms.size(); i++ )
    _rooms[i]->removeClient( cliName );
}

string ChatRoomCollection::lscr(){
  string s = "";

  for( int i = 0; i < _rooms.size(); i++ ){
    s += _rooms[i]->getRoomName();
    s += '\n';
  }

  return s;
}

string ChatRoomCollection::lssu( string cliName ){
  string s = "";

  for( int i = 0; i < _rooms.size(); i++ )
    if( _rooms[i]->clientExists( cliName ) ){
      s += _rooms[i]->getRoomName();
      s += '\n';
    }

  return s;
}
