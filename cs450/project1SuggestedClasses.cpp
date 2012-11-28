class Client {
public:
    Client( string name, ChatRoom defaultCR );

    string getID();
    bool isActive();
    void closeWriter();
    void closeReader();
    void setWriteSockDesc( int wsd );
    void setReadSockDesc( int rsd );
    void getWriteSockDesc();
    void getReadSockDesc();
    void setDefaultChatRoom( ChatRoom *chatRoom );
    ChatRoom *getDefaultChatRoom();

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
    BoundedBuffer *msgBox;

    std::string clientID;
    int rSock, wSock;
    ChatRoom *defaultChatRoom;
};

class ChatRoom {
public:
    ChatRoom( std::string roomName, std::string roomTitle );
    void setRoomName( string name );
    void setRoomTitle( string title );

    // writer thread:
    void addClient( ChatRoom *client );

    // writer thread:
    bool removeClient( std::string clientToRemove );
    int numClients();     

    // writer thread:
    // Add a message to the list of messages to be sent to all clients
    // who have subscribed to this chat-room.
    void postMessage( string message );

    // reader thread: 
    // Get a message from those deposted to the list of message for
    // distribution by "postMessage" and deliver it to all clients who
    // have subscribed to this chat-room.
    void distributeMessages();
    
private:
    std::vector< Client *> clients;
    std::list< std::string > messages; // a FCFS queue
};

template <typename T>
class BoundedBuffer {
public:
    BoundedBuffer();
    void addItem( T item );
    T getItem();

private:
    std::vector< T > buffer;
    pthread_mutex_t syncMutex;
    pthread_cond_t okToAdd;
    pthread_cond_t okToRemove;
};

void *commandThread( void *sID ) {

/*
    1. Negotiate with the client to establish a name for the client.
    2. Create the client-object and add it to the list of clients.
    3. Block until both the reader and writer processes have been created.
    4. while( the client is active ) {
           read a command from the client's socket.
           carry out the command.
           send a status back to the client.
       }
*/

  int sockID = *(reinterpret_cast<int *>(sID));

    // ...        
    // COMMAND_LEN is 4

    char command[ COMMAND_LEN + 1 ];
    int n;
    while( (n = readN( sockID, command, COMMAND_LEN ) ) == COMMAND_LEN ) {
        command[ COMMAND_LEN ] = '\0';
        // Act on it.
    }
    // clean up!
}


// client's reader thread. The server writes to its socket!
void *readerThread( void * clientObject) {
    Client *client = reinterpret_cast<Client *>(clientObject);
    
    int wDesc = client->getWriteSockDesc();
    while( client->isActive() ) {
        std::string msg = client->readMessage();
        // send this message to the client.
        flush( wDesc );
    }
    client.closeReader();
}

// client's writer thread. The server reads from it.
void *writerThread( void * clientObject ) {
    Client *client = reinterpret_cast<Client *>(clientObject);
    
    while( client->isActive() ) {
        // read msg from the client's writer process
        client->postMessage( msg );
    }
    client->closeWriter();
};

// instances of the reader/writer problem.
class ChatRoomCollection {
public:
    void addChatRoom();
    void deleteChatRoom();
    int numChatRooms();
};

// instances of the reader/writer problem.
class ClientCollection {
public:
    void addClient( Client *client );
    void deleteClient( Client *client );
    int numClients();
};
