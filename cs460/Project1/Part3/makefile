proj3: main.o Lexical.o Syntactic.o Symbol.o
	g++ -ggdb main.o Lexical.o Syntactic.o Symbol.o -o proj3

main.o: main.cpp Symbol.hpp Syntactic.hpp Lexical.hpp
	g++ -ggdb -c main.cpp

Symbol.o: Symbol.hpp Symbol.cpp token.hpp
	g++ -ggdb -c Symbol.cpp

Syntactic.o: Syntactic.hpp Syntactic.cpp Lexical.hpp parseTable.hpp token.hpp
	g++ -ggdb -c Syntactic.cpp

Lexical.o: Lexical.hpp Lexical.cpp stateTable.hpp
	g++ -ggdb -c Lexical.cpp

clean:
	rm *.o *~ proj3
