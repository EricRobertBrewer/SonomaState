proj1: main.o token.o
	g++ -ggdb main.o token.o -o proj1

main.o: main.cpp token.hpp
	g++ -ggdb -c main.cpp

token.o: token.hpp token.cpp stateTable.hpp
	g++ -ggdb -c token.cpp

clean:
	rm *.o *~ proj1
