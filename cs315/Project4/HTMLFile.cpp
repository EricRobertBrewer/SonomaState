#include "HTMLFile.hpp"

HTMLFile :: HTMLFile(){
  file = "";
}

HTMLFile :: HTMLFile( string f ){
  file = f;
}

bool HTMLFile :: insertOutTag( AnchorTag *a ){
  bool b = true;
  for( int i = 0; i <= outgoingtags.size() && b; i++ ){
    if( outgoingtags[i]->fileReference() == a->fileReference() )
      b = false;
  }
  if( b )
    outgoingtags.push_back( a );
  return b;
}

bool HTMLFile :: insertInFile( HTMLFile *h ){
  bool b = true;
  for( int i = 0; i <= incomingfiles.size() && b; i++ ){
    if( incomingfiles[i]->nameOfFile() == h->nameOfFile() )
      b = false;
  }
  if( b )
    incomingfiles.push_back( h );
  return b;
}

void HTMLFile :: print(){
  cout << endl << file << ": This file refers to these files: ";
  if( !outgoingtags.empty() )
    for( int i = 0; i <= outgoingtags.size(); i++ )
      cout << "\n\t" << outgoingtags[i]->fileReference();
  
  cout << "\nIt is referred to by these files: ";
  if( !incomingfiles.empty() )
    for( int i = 0; i <= incomingfiles.size(); i++ )
      cout <<  "\n\t" << incomingfiles[i]->nameOfFile();
  cout << endl;
}
