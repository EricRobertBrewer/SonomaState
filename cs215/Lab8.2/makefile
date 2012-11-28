lab8 : application.o LList.o
	g++ -o lab8 application.o LList.o -g

application.o : application.cpp LList.h
	g++ -c application.cpp -g

LList.o : LList.cpp LList.h
	g++ -c LList.cpp -g

clean :
	rm -f core.* *.o lab8

