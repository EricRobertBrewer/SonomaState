#ifndef TAG_READER_HPP
#define TAG_READER_HPP

#include "Parser.hpp"
#include "AnchorTag.hpp"
#include "HTMLFile.hpp"
#include "FileTree.hpp"
#include "FileTreeNode.hpp"

class TagReader{

public:
  TagReader();

  void scanInputFile( string f ); // builds tree with nodes of type HTMLFile*
  void print() { tree.print(); }

private:
  void scanHTMLFiles( FileTreeNode *n ); // recursively fills vectors of HTMLFiles
  AnchorTag *getAnchorTag(); // uses Parser to read AnchorTag syntax and data
  
  Parser parser;
  FileTree tree;

};

#endif
