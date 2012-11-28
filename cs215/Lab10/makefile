lab10 : Lab10app.o Fraction.o
	g++ -o lab10 Lab10app.o Fraction.o -g

Lab10app.o : Lab10app.cpp LList2.tmp Fraction.h
	g++ -c Lab10app.cpp -g

Fraction.o : Fraction.cpp Fraction.h
	g++ -c Fraction.cpp -g

clean :
	rm -f core.* *.o lab10

