#ifndef MY_MAKEFILE_HPP
#define MY_MAKEFILE_HPP

#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

#include "Scanner.hpp"
#include "Token.hpp"
#include "MakeNameNode.hpp"
#include "ItemLinkNode.hpp"
#include "MakeTree.hpp"
#include "MakeTreeNode.hpp"
#include "systemInterface.h"

class MyMakefile {
public:
    MyMakefile( string name );
    void print();
    void parseMakefile();
    void runMake();
    MakeNameNode *mostRecentDependency( MakeNameNode *targ ) 
      { return mostRecentDependency( targ->nextItem() ); }

private:
    void runMake( MakeNameNode *targ );
    void buildDependencyList( MakeNameNode *targ );
    bool isCyclic( MakeNameNode *n );
    MakeNameNode *mostRecentDependency( ItemLinkNode *i );
    void die( string exp, Token t );

private:
    string fileToMake, targetToMake;
    MakeTree *tree;
    Scanner scanner;
};

#endif
