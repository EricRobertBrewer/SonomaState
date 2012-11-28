#include "MyMakefile.hpp"

MyMakefile :: MyMakefile( string name ){
  fileToMake = name;
  targetToMake = "";
  tree = NULL;
  scanner.fileName() = name;
  scanner.open();
}

void MyMakefile :: print(){
  cout << "File to make: " << fileToMake
       << "\nFirst target of file: " << targetToMake;
}

void MyMakefile :: parseMakefile(){
  scanner.open( fileToMake );
  tree = new MakeTree();
  Token tok;
  cout << "1" << endl;  
  while( !( tok = scanner.getToken() ).eof() ){
    if( !tok.isAName() )
      die( "a name", tok );
    cout << "2" << endl;
    MakeNameNode *target = tree->find( tok.name() );
    if( !target ){
      target = new MakeNameNode( tok.name() );
      
      long timeOfFile;
      if( !timestamp( target->name().c_str(), & timeOfFile ) ){
	cout << "\nCouldn't stat " << target->name() << ".\n";
	exit(1);
      }
      if( timeOfFile == -1 ){
	cout << "\nFile " << target->name() << "does not exist.\n";
	exit(1);
      }
      
      target->timeStamp() = timeOfFile;
      tree->insert( target );
    }
    cout << "3" << endl;
    tok = scanner.getToken();
    if( !tok.isAColon() )
      die( "a colon", tok );
    tree->print();
    buildDependencyList( target );

    tok = scanner.getToken();
    if( !tok.isATab() )
      die( "a tab", tok );

    target->command() = scanner.readCommand();
  }

  if( !tree ){
    cout << "\nFile is empty.\n";
    exit(1);
  }

  targetToMake = tree->getRoot()->nameNode()->name();
}

void MyMakefile :: runMake(){
  if( !tree )
    parseMakefile();

  if( isCyclic( tree->find( targetToMake ) ) ){
    cout << "\nYour makefile contains a cycle.\n";
    print();
    cout << endl;
    exit(1);
  }

  runMake( tree->find( targetToMake ) );
}

void MyMakefile :: runMake( MakeNameNode *targ ){
  if( !targ->nextItem() )
    return;

  for( ItemLinkNode *c = targ->nextItem(); c; c = c->nextNode() ){
    runMake( c->getNameNode() );
  }

  if( targ->timeStamp() < mostRecentDependency( targ )->timeStamp() )
    targ->runCommand();
}

void MyMakefile :: buildDependencyList( MakeNameNode *targ ){
  Token token;

  while( !( token = scanner.getToken() ).eol() && !token.eof() ){
    if( !token.isAName() )
      die( "a name", token );

    MakeNameNode *item = tree->find( token.name() );
    if( !item ){
      item = new MakeNameNode( token.name() );

      long timeOfFile;
      if( !timestamp( item->name().c_str(), & timeOfFile ) ){
        cout << "\nCouldn't stat " << item->name() << ".\n";
        exit(1);
      }
      if( timeOfFile == -1 ){
        cout << "\nFile " << item->name() << "does not exist.\n";
        exit(1);
      }

      item->timeStamp() = timeOfFile;
      tree->insert( item );
    }

    ItemLinkNode *link = new ItemLinkNode( item );
    link->nextNode( targ->nextItem() );
    targ->nextItem( link );
  }
}

bool MyMakefile :: isCyclic( MakeNameNode *n ){
  if( n->isOnPath() )
    return true;

  n->isOnPath() = true;
  for( ItemLinkNode *c = n->nextItem(); c; c = c->nextNode() )
    if( isCyclic( c->getNameNode() ) )
      return true;
  
  n->isOnPath() = false;
  return false; 
}

void MyMakefile :: die( string exp, Token t ){
  cout << "Error: expected [" << exp << "].\nReceived Token:\n";
  t.print();
  cout << endl;

  exit(1);
}

MakeNameNode * MyMakefile :: mostRecentDependency( ItemLinkNode *i ){
  if( i->nextNode() == NULL )
    return i->getNameNode();

  MakeNameNode *m = mostRecentDependency( i->nextNode() );

  if( i->getNameNode()->timeStamp() > m->timeStamp() )
    return i->getNameNode();
  return m;
}

