proj3 : application.o Maze.o
	g++ -ggdb -o proj3 application.o Maze.o

application.o : application.cpp Maze.h
	g++ -ggdb -c application.cpp

Maze.o : Maze.cpp Maze.h
	g++ -ggdb -c Maze.cpp

clean :
	rm -f core.* *.o proj3
