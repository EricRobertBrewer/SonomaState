#ifndef MAKE_TREE_HPP
#define MAKE_TREE_HPP

#include<iostream>
#include<string>
using namespace std;

#include "MakeTreeNode.hpp"
#include "MakeNameNode.hpp"

class MakeTree {
public:
    MakeTree(): root(0) {}
    void insert( MakeNameNode *nNode ) { root = insert( root, nNode ); }
    MakeNameNode *find( string name ) { return find( root, name ); }
    void print() { print( root ); }
  
    MakeTreeNode *getRoot() { return root; }

private: 
    MakeTreeNode *insert( MakeTreeNode*, MakeNameNode* );
    MakeNameNode *find( MakeTreeNode*, string );
    void print( MakeTreeNode* );

    MakeTreeNode *root;
};

#endif
