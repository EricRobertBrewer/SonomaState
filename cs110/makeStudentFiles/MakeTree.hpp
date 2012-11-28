#include<iostream>
#include<string>

using namespace std;

class TreeNode;

class MakeTree {
public:
    MakeTree(): root(0) {}
    void insert( MakeNameNode *nNode );
    MakeNameNode *find( string name );
    void print();

private:
    TreeNode *root;
};
