#include<iostream>

#include "MakeNameNode.hpp"
#include "MakeTree.hpp"

#include "systemInterface.hpp"

int main( int argc, char **argv ) {
    long numSecondsSinceJan1st1997;

    if( argc != 2 ) {
        std::cerr << argv[0] << ":: usage: " << argv[0] << " aFileName\n";
        return 1;
    }
    if( ! timestamp( argv[1], & numSecondsSinceJan1st1997 ) ) {
        std::cout << "Couldn't stat " << argv[1] << "!\n";
        return 1;
    }
    if( numSecondsSinceJan1st1997 == -1 ) {
        std::cout << "File " << argv[1] << " does not exist!\n";
        return 0;
    }
    std::cout << "Timestamp of " << argv[1] << " is: " << numSecondsSinceJan1st1997
         << std::endl;
    return 0;
}
