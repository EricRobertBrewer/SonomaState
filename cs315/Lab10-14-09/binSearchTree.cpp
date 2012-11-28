#include "binSearchTree.hpp"
#include<deque>
#include<iostream>

BinSearchTree::BinSearchTree(){
  root = NULL;
}

int BinSearchTree::valuesAtLevel( int k ){
  deque<TreeNode*> vals;
  int stored = 0;

  if( root )
    vals.push_back( root );  
  
  stored = vals.size();

  for(int i = 1; i < k; i++){
    if( stored ){
      for(int j = 0; j < stored; j++){
	if( vals[j]->leftSubtree() )
	  vals.push_back( vals[j]->leftSubtree() );
	if( vals[j]->rightSubtree() )
          vals.push_back( vals[j]->rightSubtree() );
      }
      for(int a = 0; a < stored; a++)
	vals.pop_front();
      stored = vals.size();
    }
  }

  for(int n = 0; n < stored; n++)
    cout << vals[n]->value() << ' ';
  
  return k;
}

/*
int BinSearchTree::kthSmallest( int k ){

}
*/

int BinSearchTree::size( TreeNode *root ){
  if( root == NULL )
    return 0;
  return 1 + size( root->leftSubtree() ) + size( root->rightSubtree() );
}

void BinSearchTree::levelorderDump(){
  deque<TreeNode*> nodes;
  if( root )
    nodes.push_back( root );

  while( nodes.size() ){
    if( nodes.front()->leftSubtree() )
      nodes.push_back( nodes.front()->leftSubtree() );
    if( nodes.front()->rightSubtree() )
      nodes.push_back( nodes.front()->rightSubtree() );
    cout << nodes.front()->value() << ' ';
    nodes.pop_front();
  }
}

bool BinSearchTree::find( TreeNode *root, int v ){
  if( root == NULL )
    return false;
  if( root->value() == v )
    return true;
  if( root->value() < v )
    return find( root->rightSubtree(), v );
  else
    return find( root->leftSubtree(), v );
}

void BinSearchTree::inorderDump( TreeNode *root ){
  if( root == NULL )
    return;
  inorderDump( root->leftSubtree() );
  cout << root->value() << ' ';
  inorderDump( root->rightSubtree() );
}

TreeNode *BinSearchTree::insert( TreeNode *root, int v ) {
  if( root == NULL )
    return new TreeNode( v );
  if( root->value() < v )
    root->rightSubtree( insert( root->rightSubtree(), v ) );
  if( root->value() > v )
    root->leftSubtree( insert( root->leftSubtree(), v ) );
  return root;
}
