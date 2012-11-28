/*
Client.cpp
Eric Brewer
10/26/10
Kooshesh
CS450 - Operating Systems
Chat Program: Client class implementation - 
*/

#include "Client.hpp"
#include "ChatRoom.hpp"
#include "BoundedBuffer.hpp"

Client::Client( string name, ChatRoom *defaultCR ){

  _msgBox = new BoundedBuffer<string>();
  _clientID = name;
  _defaultChatRoom = defaultCR;
  _commandSock = -1;
  _readerSock = -1;
  _writerSock = -1;
}

bool Client::isActive(){

  return( ( _readerSock > 0 ) && ( _writerSock > 0 ) );
}

void Client::closeWriter(){

}

void Client::closeReader(){

}

void Client::setCommandSockDesc( int csd ){

  _commandSock = csd;
}

void Client::setReaderSockDesc( int rsd ){

  _readerSock = rsd;
}

void Client::setWriterSockDesc( int wsd ){

  _writerSock = wsd;
}

void Client::setDefaultChatRoom( ChatRoom *chatRoom ){

  _defaultChatRoom = chatRoom;
}

string Client::readChatMessage(){

  return _msgBox->removeItem();
}

void Client::writeChatMessage( string msg ){

  _msgBox->addItem( msg );
}

void Client::postMessageToDefaultChatRoom( string msg ){

  _defaultChatRoom->postMessage( msg );
}
