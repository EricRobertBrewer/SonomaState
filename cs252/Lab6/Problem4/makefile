Lab06.out: main.o f1a.o f1b.o f1c.o f2a.o f2b.o f2c.o
	gcc main.o f1a.o f1b.o f1c.o f2a.o f2b.o f2c.o -o Lab06.out

main.o: main.c
	gcc -c main.c -o main.o

f1a.o: f1a.s
	as f1a.s -o f1a.o

f1b.o: f1b.s
	as f1b.s -o f1b.o

f1c.o: f1c.s
	as f1c.s -o f1c.o

f2a.o: f2a.s
	as f2a.s -o f2a.o

f2b.o: f2b.s
	as f2b.s -o f2b.o

f2c.o: f2c.s
	as f2c.s -o f2c.o

