lab14 : Lab14.o polygon.o
	g++ -o lab14 Lab14.o polygon.o -g

Lab14.o : Lab14.cpp polygon.h
	g++ -c Lab14.cpp -g 

polygon.o : polygon.cpp polygon.h
	g++ -c polygon.cpp -g

clean :
	rm -f core.* *.o lab14

