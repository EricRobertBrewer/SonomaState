#ifndef ANCHOR_TAG_HPP
#define ANCHOR_TAG_HPP

#include <string>
using namespace std;

class AnchorTag{

public:
  AnchorTag( string r, string t ): _file_ref( r ), _page_text( t ) {}

  string fileReference() { return _file_ref; }
  string pageText() { return _page_text; }

private:
  string _file_ref;
  string _page_text;

};

#endif
