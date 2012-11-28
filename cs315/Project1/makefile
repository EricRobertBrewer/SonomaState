screen.x:  screen.o getChar.o Cell.o
	g++ -ggdb -o screen.x Cell.o screen.o getChar.o -lcurses -ltermcap

Cell.o: Cell.cpp Cell.hpp
	g++ -ggdb -c Cell.cpp -o Cell.o

screen.o: screen.cpp
	g++ -ggdb -c screen.cpp -o screen.o

getChar.o: getChar.cpp
	gcc -ggdb -c getChar.cpp -o getChar.o

clean:
	/bin/rm -f screen.x screen.o getChar.o Cell.o *~
