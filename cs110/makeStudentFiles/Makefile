make.x: main.o systemInterface.o
	g++ -g main.o systemInterface.o -o make.x

systemInterface.o: systemInterface.hpp systemInterface.cpp
	gcc -g -c systemInterface.cpp

main.o: main.cpp systemInterface.hpp
	g++ -g -c main.cpp

clean:
	rm -f *.o make.x *~
