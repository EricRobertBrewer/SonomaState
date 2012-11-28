#ifndef HTML_FILE_TREE_NODE_HPP
#define HTML_FILE_TREE_NODE_HPP

#include "HTMLFile.hpp"

class FileTreeNode{
  
public:
  FileTreeNode( HTMLFile *h ): _filedata( h ), _left( 0 ), _right( 0 ) {}
  
  FileTreeNode *left() { return _left; }
  FileTreeNode *right() { return _right; }
  void left( FileTreeNode *l ) { _left = l; }
  void right( FileTreeNode *r ) { _right = r; }
  void print() { _filedata->print(); }

  HTMLFile *fileData() { return _filedata; }

private:
  HTMLFile *_filedata;
  FileTreeNode *_left, *_right;
  
};

#endif
