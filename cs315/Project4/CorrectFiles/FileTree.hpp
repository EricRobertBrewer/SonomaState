#ifndef HTML_FILE_TREE_HPP
#define HTML_FILE_TREE_HPP

#include "HTMLFile.hpp"
#include "FileTreeNode.hpp"

#include <string>
using namespace std;

class FileTree{

public:
  FileTree(): _root( 0 ) {}

  void insert( HTMLFile *h ) { _root = insert( _root, h ); }
  HTMLFile *find( string name ) { return find( _root, name ); }
  void print() { print( _root ); }
  FileTreeNode *root() { return _root; }

private:
  FileTreeNode *insert( FileTreeNode *n, HTMLFile *h );
  HTMLFile *find( FileTreeNode *n, string name );
  void print( FileTreeNode *n );

  FileTreeNode *_root;

};

#endif
