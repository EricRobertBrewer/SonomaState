crossReference.x: main.o FileTree.o HTMLFile.o TagReader.o Parser.o
	g++ main.o FileTree.o HTMLFile.o TagReader.o Parser.o -o crossReference.x

main.o: main.cpp TagReader.hpp
	g++ -c main.cpp -o main.o

FileTree.o: FileTree.cpp FileTree.hpp FileTreeNode.hpp
	g++ -c FileTree.cpp -o FileTree.o

HTMLFile.o: HTMLFile.cpp HTMLFile.hpp AnchorTag.hpp
	g++ -c HTMLFile.cpp -o HTMLFile.o

TagReader.o: TagReader.cpp TagReader.hpp FileTree.hpp FileTreeNode.hpp HTMLFile.hpp AnchorTag.hpp Parser.hpp
	g++ -c TagReader.cpp -o TagReader.o

Parser.o: Parser.cpp Parser.hpp 
	g++ -c Parser.cpp -o Parser.o