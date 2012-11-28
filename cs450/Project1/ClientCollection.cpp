/*
ClientCollection.cpp
Eric Brewer
10/26/10
Kooshesh
CS450 - Operating Systems
Chat Program: ClientCollection class implementation - 
*/

#include "ClientCollection.hpp"
#include "Client.hpp"

ClientCollection::ClientCollection(){

  _clients.clear();
}

bool ClientCollection::addClient( Client *client ){
  bool found = false;
  
  for( int i = 0; i < _clients.size() && !found; i++ )
    if( client->getID() == _clients[i]->getID() )
      found = true;

  if( !found )
    _clients.push_back( client );

  return !found;
}

bool ClientCollection::deleteClient( string clientName ){
  bool found = false;
  int i;

  for( i = 0; i < _clients.size() && !found; i++ )
    if( clientName == _clients[i]->getID() )
      found = true;

  if( found ){
    _clients[i] = _clients.back();
    _clients.pop_back();
  }

  return found;
}

Client *ClientCollection::exists( string clientName ){

  for( int i = 0; i < _clients.size(); i++ )
    if( clientName == _clients[i]->getID() )
      return _clients[i];

  return NULL;
}
