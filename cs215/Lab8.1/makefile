lab8 : application.o AList.o
	g++ -o lab8 application.o AList.o -g

application.o : application.cpp AList.h
	g++ -c application.cpp -g

AList.o : AList.cpp AList.h
	g++ -c AList.cpp -g

clean :
	rm -f core.* *.o lab8

