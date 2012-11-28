/*
Client.hpp
Eric Brewer
10/26/10
Kooshesh
CS450 - Operating Systems
Chat Program: Client class header - 
*/

#ifndef _CLIENT_HPP
#define _CLIENT_HPP

#include <string>
using namespace std;
class ChatRoom;
template <typename T> class BoundedBuffer;

class Client{
public:
  Client( string name, ChatRoom *defaultCR );
  
  string getID() { return _clientID; }
  bool isActive();
  void closeWriter();
  void closeReader();
  void setCommandSockDesc( int csd );
  void setWriterSockDesc( int wsd );
  void setReaderSockDesc( int rsd );
  void setDefaultChatRoom( ChatRoom *chatRoom );
  int getCommandSockDesc() { return _commandSock; }
  int getWriterSockDesc() { return _writerSock; }
  int getReaderSockDesc() { return _readerSock; }
  ChatRoom *getDefaultChatRoom() { return _defaultChatRoom; }
  
  // consumer thread:
  // Gets a message from the msgBox of the client to which this
  // object belongs and sends it to the client's reader
  // process. Notice that no reading takes place here. Instead, the
  // messages that are deposited into this client's "message box",
  // are taken out, one at a time, by this function and transmitted
  // to the reader process of this client.
  string readChatMessage();  
  
  // producer thread:
  // adds a message to the msgBox of this client so that it can
  // ultimately be sent to the client through a call, by the thread
  // that represent the read process of the client, to the
  // "readChatMessage()".
  void writeChatMessage( string msg );
  
  // Post this message to the default chat-room of this client.  The
  // thread that represents the writer process of the client that
  // this object serves, after having received a message from it,
  // calls this function to deliver the message for posting. These
  // messages are posted to the default chat-room of the client that
  // owns this object and not into the "message box" of this
  // client. However, the chat-room, after it receives the message,
  // ultimately calls the "writeChatMessage" of every client who has
  // subscribed to this chat-room, including this client.
  void postMessageToDefaultChatRoom( string msg );
  
private:
  BoundedBuffer<string> *_msgBox;
  
  string _clientID;
  int _commandSock, _readerSock, _writerSock;
  ChatRoom *_defaultChatRoom;

};

#endif
