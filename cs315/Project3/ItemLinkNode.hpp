#ifndef ITEM_LINK_NODE_HPP
#define ITEM_LINK_NODE_HPP

#include<iostream>
#include<string>

using namespace std;

class MakeNameNode; 

class ItemLinkNode {
public:
    ItemLinkNode( MakeNameNode *nNode ): _nextNode(0), nameNode( nNode ) {}
    void nextNode( ItemLinkNode *next ) { _nextNode = next; }
    ItemLinkNode *nextNode() { return _nextNode; }
    MakeNameNode *getNameNode() { return nameNode; }

private:
    ItemLinkNode *_nextNode;
    MakeNameNode *nameNode;
};

#endif
