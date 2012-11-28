lab11 : Lab11App.o card.o
	g++ -o lab11 Lab11App.o card.o -g

Lab11App.o : Lab11App.cpp LList2.tmp card.h
	g++ -c Lab11App.cpp -g -w

card.o : card.cpp card.h
	g++ -c card.cpp -g

clean :
	rm -f core.* *.o lab11

