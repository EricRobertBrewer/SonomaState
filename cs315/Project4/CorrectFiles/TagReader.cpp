#include "TagReader.hpp"

TagReader :: TagReader(){
  
}

void TagReader :: scanInputFile( string f ){
  parser.open( f );
  while( !parser.eof() ){
    HTMLFile *h = new HTMLFile( parser.readString() );
    tree.insert( h );
  }
  scanHTMLFiles( tree.root() );
}

void TagReader :: scanHTMLFiles( FileTreeNode *n ){
  if( n == NULL )
    return;

  scanHTMLFiles( n->left() );
  
  parser.open( n->fileData()->nameOfFile() );
  while( !parser.eof() ){
    parser.walkUntil( '<' );
    if( parser.matchNext( 'a' ) ){
      AnchorTag *a = getAnchorTag();
      if( a ){
	n->fileData()->insertOutTag( a );
	HTMLFile *h = tree.find( a->fileReference() );
	if( h )
	  h->insertInFile( h );
      }
    }
  }

  scanHTMLFiles( n->right() );
}

AnchorTag * TagReader :: getAnchorTag(){
  string file_ref = "";
  string text = "";
  AnchorTag *a = NULL;
  
  if( parser.matchNext( "href" ) &&
      parser.matchNext( '=' ) &&
      parser.matchNext( '"' ) )
    file_ref = parser.readStringUntil( '"' );
  else
    return NULL;
  
  if( parser.matchNext( '"' ) &&
      parser.matchNext( '>' ) )
    text = parser.readStringUntil( '<' );
  else
    return NULL;
  
  if( parser.matchNext( '<' ) &&
      parser.matchNext( "/a" ) &&
      parser.matchNext( '>' ) )
    a = new AnchorTag( file_ref, text );
  else
    return NULL;
  
  return a;
}
