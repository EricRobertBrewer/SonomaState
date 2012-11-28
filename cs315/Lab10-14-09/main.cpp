#include "treeNode.hpp"
#include "binSearchTree.hpp"
#include<fstream>
#include<iostream>
using namespace std;

int main( int argc, char *argv[] ){
  BinSearchTree *tree = new BinSearchTree();
  
  ifstream fin;
  fin.open("me.input");
  
  int v;
  while( fin >> v ){
    if( !tree->find( v ) )
      tree->insert( v );
  }

  fin.close();

  cout << "In order dump: " << endl;
  tree->inorderDump();
  
  cout << endl << "Tree size: " << tree->size() << endl;

  cout << "Level order dump: " << endl;
  tree->levelorderDump();

  cout << endl;
  return 0;
}
