#include "FileTree.hpp"

FileTreeNode * FileTree :: insert( FileTreeNode *n, HTMLFile *h ){
  if( n == NULL )
    return new FileTreeNode( h );
  if( n->fileData()->nameOfFile() > h->nameOfFile() )
    n->left( insert( n->left(), h ) );
  if( n->fileData()->nameOfFile() < h->nameOfFile() )
    n->right( insert( n->right(), h ) );
  return n;    
}

HTMLFile * FileTree :: find( FileTreeNode *n, string name ){
  if( n == NULL )
    return NULL;
  if( n->fileData()->nameOfFile() > name )
    return find( n->left(), name );
  if( n->fileData()->nameOfFile() < name )
    return find( n->right(), name );
  return n->fileData();
}

void FileTree :: print( FileTreeNode *n ){
  if( n == NULL )
    return;
  print( n->left() );
  n->print();
  print( n->right() );
}
