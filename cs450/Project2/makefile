shell.x: shell.o Parser.o
	g++ shell.o Parser.o -o shell.x

shell.o: shell.cpp Parser.hpp
	g++ -c shell.cpp

Parser.o: Parser.hpp Parser.cpp
	g++ -c Parser.cpp

clean:
	rm *~ *# *.x *.o

