p2: main.o io.o
	gcc main.o io.o -o p2

main.o: main.s
	as main.s -o main.o

io.o: io.s
	as io.s -o io.o