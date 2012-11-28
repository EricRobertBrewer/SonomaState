/*
ChatRoom.cpp
Eric Brewer
10/26/10
Kooshesh
CS450 - Operating Systems
Chat Program: ChatRoom class implementation - 
*/

#include "ChatRoom.hpp"
#include "Client.hpp"
#include "BoundedBuffer.hpp"

ChatRoom::ChatRoom( string roomName ){

  _messages = new BoundedBuffer<string>();
  _name = roomName;
  _clients.clear();
}

void ChatRoom::setRoomName( string name ){

  _name = name;
}

bool ChatRoom::addClient( Client *client ){
  bool found = false;

  for( int i = 0; i < _clients.size() && !found; i++ )
    if( client->getID() == _clients[i]->getID() )
      found = true;

  if( !found )
    _clients.push_back( client );

  return !found;
}

bool ChatRoom::removeClient( string clientToRemove ){
  bool found = false;

  int i;
  for( i = 0; i < _clients.size() && !found; i++ )
    if( clientToRemove == _clients[i]->getID() )
      found = true;

  if( found ){
    _clients[i] = _clients.back();
    _clients.pop_back();
  }

  return found;
}

void ChatRoom::postMessage( string message ){

  _messages->addItem( message );
}

void ChatRoom::distributeMessages(){

  string message = _messages->removeItem();
  for( int i = 0; i < _clients.size(); i++ )
    _clients[i]->writeChatMessage( message );
}

Client *ChatRoom::clientExists( string cliName ){

  for( int i = 0; i < _clients.size(); i++ )
    if( cliName == _clients[i]->getID() )
      return _clients[i];

  return NULL;
}
