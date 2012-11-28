#include "MakeTree.hpp"

MakeTreeNode * MakeTree :: insert( MakeTreeNode *tNode, MakeNameNode* nNode ){
  if( !tNode )
    return new MakeTreeNode( nNode );
  
  if( tNode->nameNode()->name().compare( nNode->name() ) > 0 )
    tNode->left( insert( tNode->left(), nNode ) );
  if( tNode->nameNode()->name().compare( nNode->name() ) < 0 )
    tNode->right( insert( tNode->right(), nNode ) );
  return tNode;
}

MakeNameNode * MakeTree :: find( MakeTreeNode *tNode, string s ){
  if( !tNode )
    return NULL;

  if( tNode->nameNode()->name().compare(s) == 0 )
    return tNode->nameNode();
  if( tNode->nameNode()->name().compare(s) > 0 )
    return find( tNode->left(), s );
  else
    return find( tNode->right(), s );
}

void MakeTree :: print( MakeTreeNode *tNode ){
  if( !tNode )
    return;

  print( tNode->left() );
  cout << tNode->nameNode()->name() << endl;
  print( tNode->right() );
}
