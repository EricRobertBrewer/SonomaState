screen.x:  screen.o getChar.o
	g++ -ggdb -o screen.x screen.o getChar.o -lcurses -ltermcap

screen.o: screen.cpp
	g++ -ggdb -c screen.cpp -o screen.o

getChar.o: getChar.cpp 
	gcc -ggdb -c getChar.cpp -o getChar.o

clean:
	/bin/rm -f screen.x screen.o getChar.o
