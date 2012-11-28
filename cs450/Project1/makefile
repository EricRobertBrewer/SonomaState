all: cProcess.x rProcess.x wProcess.x server.x


cProcess.x: cProcess.cpp
	g++ -pthread cProcess.cpp -o cProcess.x

rProcess.x: rProcess.cpp
	g++ -pthread rProcess.cpp -o rProcess.x

wProcess.x: wProcess.cpp
	g++ -pthread wProcess.cpp -o wProcess.x

server.x: server.cpp Client.o ChatRoom.o ClientCollection.o ChatRoomCollection.o
	g++ -pthread server.cpp Client.o ChatRoom.o ClientCollection.o ChatRoomCollection.o -o server.x

Client.o: Client.hpp Client.cpp ChatRoom.hpp BoundedBuffer.hpp
	g++ -c Client.cpp

ChatRoom.o: ChatRoom.hpp ChatRoom.cpp Client.hpp BoundedBuffer.hpp
	g++ -c ChatRoom.cpp

BoundedBuffer.o: BoundedBuffer.hpp 
	g++ -c BoundedBuffer.hpp

ChatRoomCollection.o: ChatRoomCollection.hpp ChatRoomCollection.cpp ChatRoom.hpp
	g++ -c ChatRoomCollection.cpp

ClientCollection.o: ClientCollection.hpp ClientCollection.cpp Client.hpp
	g++ -c ClientCollection.cpp

clean:
	rm *~ *# *.x *.o
