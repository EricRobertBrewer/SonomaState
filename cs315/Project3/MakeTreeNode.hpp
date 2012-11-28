#ifndef MAKE_TREE_NODE_HPP
#define MAKE_TREE_NODE_HPP

#include<iostream>
#include<string>
using namespace std;

#include "MakeNameNode.hpp"

class MakeTreeNode {
public:
    MakeTreeNode( MakeNameNode *nNode ): makeNode( nNode ), leftSubtree(0), rightSubtree(0) {}

    MakeTreeNode *left() { return leftSubtree; }
    void left( MakeTreeNode *leftPtr ) { leftSubtree = leftPtr; }
    MakeTreeNode *right() { return rightSubtree; }
    void right( MakeTreeNode *rightPtr ) { rightSubtree = rightPtr; }
    MakeNameNode *nameNode() { return makeNode; }

    void print() { makeNode->print(); } 

private:
    MakeNameNode *makeNode;
    MakeTreeNode *leftSubtree, *rightSubtree;
};

#endif
