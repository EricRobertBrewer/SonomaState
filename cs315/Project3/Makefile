make.x: main.o MakeNameNode.o MakeTree.o MyMakefile.o Scanner.o systemInterface.o Token.o
	g++ -g main.o MakeNameNode.o MakeTree.o MyMakefile.o Scanner.o systemInterface.o Token.o -o make.x
main.o: main.cpp MyMakefile.hpp systemInterface.h
	g++ -c main.cpp
MakeNameNode.o: MakeNameNode.cpp MakeNameNode.hpp MakeTreeNode.hpp ItemLinkNode.hpp systemInterface.h
	g++ -c MakeNameNode.cpp
MakeTree.o: MakeTree.cpp MakeTree.hpp MakeTreeNode.hpp MakeNameNode.hpp
	g++ -c MakeTree.cpp
MyMakefile.o: MyMakefile.cpp MyMakefile.hpp Scanner.hpp Token.hpp MakeTree.hpp MakeNameNode.hpp ItemLinkNode.hpp systemInterface.h
	g++ -c MyMakefile.cpp
Scanner.o: Scanner.cpp Scanner.hpp Token.hpp
	g++ -c Scanner.cpp
systemInterface.o: systemInterface.c systemInterface.h
	gcc -c systemInterface.c
Token.o: Token.cpp Token.hpp 
	g++ -c Token.cpp
