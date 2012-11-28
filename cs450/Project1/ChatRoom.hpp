/*
ChatRoom.hpp
Eric Brewer
10/26/10
Kooshesh
CS450 - Operating Systems
Chat Program: ChatRoom class header -
*/

#ifndef _CHATROOM_HPP
#define _CHATROOM_HPP

#include <vector>
#include <string>
using namespace std;
class Client;
template <typename T> class BoundedBuffer;

class ChatRoom {
public:
  ChatRoom( string roomName );
  void setRoomName( string name );
  
  string getRoomName() { return _name; }

  // writer thread:
  bool addClient( Client *client );
  
  // writer thread:
  bool removeClient( string clientToRemove );
  int numClients() { return _clients.size(); }     
  
  // writer thread:
  // Add a message to the list of messages to be sent to all clients
  // who have subscribed to this chat-room.
  void postMessage( string message );
  
  // reader thread: 
  // Get a message from those deposted to the list of message for
  // distribution by "postMessage" and deliver it to all clients who
  // have subscribed to this chat-room.
  void distributeMessages();

  Client *clientExists( string cliName );

private:
  string _name;
  vector<Client *> _clients;
  BoundedBuffer<string> *_messages; // a FCFS queue

};

#endif
