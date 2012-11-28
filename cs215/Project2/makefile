proj2 : application.o polynomial.o
	g++ -ggdb -o proj2 application.o polynomial.o

application.o : application.cpp polynomial.h
	g++ -ggdb -c application.cpp

polynomial.o : polynomial.cpp polynomial.h
	g++ -ggdb -c polynomial.cpp

clean : 
	rm -f core.* *.o proj2
