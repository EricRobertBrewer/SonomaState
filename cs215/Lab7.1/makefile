lab7 : application.o worddata.o
	g++ -o lab7 application.o worddata.o

application.o : application.cpp sorts.h worddata.h
	g++ -c application.cpp

worddata.o : worddata.cpp worddata.h
	g++ -c worddata.cpp

clean : 
	rm -f core.* *.o lab7
