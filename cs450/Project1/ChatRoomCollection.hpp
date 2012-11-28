/*
ChatRoomCollection.hpp
Eric Brewer
10/26/10
Kooshesh
CS450 - Operating Systems
Chat Program: ChatRoomCollection class header - 
*/

#ifndef _CHATROOMCOLLECTION_HPP
#define _CHATROOMCOLLECTION_HPP

#include <string>
using namespace std;
#include <vector>
class ChatRoom;

class ChatRoomCollection{
public:
  ChatRoomCollection();
  bool addChatRoom( ChatRoom *chatRoom );
  bool deleteChatRoom( string chatRoomName );
  int numChatRooms() { return _rooms.size(); }
  ChatRoom *exists( string cRName );
  void wipeClient( string cliName );

  string lscr();
  string lssu( string cliName );

private:
  vector<ChatRoom *> _rooms;

};

#endif
