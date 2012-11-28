.SUFFIXES: .cpp .o

OBJS = parser.o lex.o reclists.o mySolution.o main.cpp 

reclists.x:  $(OBJS)
	g++ -ggdb -o reclists.x $(OBJS)

.cpp.o:
	g++ -c -ggdb $< -o $@

parser.o: parser.cpp lex.hpp reclists.hpp
lex.o: lex.cpp lex.hpp
reclists.o: reclists.hpp reclists.cpp
mySolution.o: reclists.hpp mySolution.hpp mySolution.cpp 
main.o: main.cpp reclists.hpp

clean:
	rm -f *.o *.x *~
