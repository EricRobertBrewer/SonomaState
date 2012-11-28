lab9 : application.o CoordPt.o
	g++ -o lab9 application.o CoordPt.o -g

application.o : application.cpp LList.tmp CoordPt.h
	g++ -c application.cpp -g

CoortPt.o : CoordPt.cpp CoordPt.h
	g++ -c CoordPt.cpp -g

clean : 
	rm -f core.* *.o lab
 