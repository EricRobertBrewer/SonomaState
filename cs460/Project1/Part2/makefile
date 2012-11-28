proj2: main.o Lexical.o Syntactic.o
	g++ -ggdb main.o Lexical.o Syntactic.o -o proj2

main.o: main.cpp Syntactic.hpp
	g++ -ggdb -c main.cpp

Syntactic.o: Syntactic.hpp Syntactic.cpp Lexical.hpp parseTable.hpp token.hpp
	g++ -ggdb -c Syntactic.cpp

Lexical.o: Lexical.hpp Lexical.cpp stateTable.hpp
	g++ -ggdb -c Lexical.cpp

clean:
	rm *.o *~ proj2
