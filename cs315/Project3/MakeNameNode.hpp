#ifndef MAKE_NAME_NODE_HPP
#define MAKE_NAME_NODE_HPP

#include<iostream>
#include<string>
using namespace std;
#include<stdlib.h>

#include "ItemLinkNode.hpp"
#include "systemInterface.h"

class MakeNameNode {
public:
    MakeNameNode( string name ): _name( name ), _timeStamp(0), _nextItem(0), _command(""), _isOnPath(0) {}
    string &name() { return _name; }
    int &timeStamp() { return _timeStamp; }
    ItemLinkNode *nextItem() { return _nextItem; }
    void nextItem( ItemLinkNode *next ) { _nextItem = next; }
    string &command() { return _command; }
    bool &isOnPath() { return _isOnPath; }

    void runCommand();  // execute the command associated with this node.
    void print();

private:
    string _name;
    int _timeStamp;
    ItemLinkNode *_nextItem;
    string _command;
    bool _isOnPath;
};

#endif
