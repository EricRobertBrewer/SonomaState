#include<iostream>
#include<string>

using namespace std;

class TreeNode {
public:
    TreeNode( MakeNameNode *nNode ): makeNode( nNode ), left(0), right(0) {}

    TreeNode *leftSubtree() { return left; }
    void leftSubtree( TreeNode *leftPtr ) { left = leftPtr; }
    TreeNode *rightSubtree() { return right; }
    void rightSubtree( TreeNode *rightPtr ) { right = rightPtr; }

    void print() { makeNode->print(); } 

private:
    MakeNameNode *makeNode;
    TreeNode *left, *right;
};
