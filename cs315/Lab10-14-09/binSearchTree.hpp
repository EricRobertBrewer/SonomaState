#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "treeNode.hpp"
#include<iostream>
using namespace std;

class BinSearchTree {
public:
  BinSearchTree();
  
  int valuesAtLevel( int k );
  //int kthSmallest( int k );
  bool find( int v ) { return find( root, v ); }
  int size() { return size( root ); }
  void inorderDump() { inorderDump( root ); }
  void levelorderDump();
  void insert( int v ) { root = insert( root, v ); }

private:
  bool find( TreeNode *, int );
  int size( TreeNode * );
  void inorderDump( TreeNode* );
  TreeNode *insert( TreeNode *, int );
  TreeNode *root;
};

#endif
