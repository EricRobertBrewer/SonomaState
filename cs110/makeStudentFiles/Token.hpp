#include<iostream>
#include<string>

using namespace std;

class Token {
public:
    Token( string name ) { 
        initialize(); 
        _name = name;
    }
    Token() { initialize(); }

    void print();
    bool isAName()   { return _name.length() != 0; }
    string &name()   { return _name; }
    bool &isAColon() { return _isAColon; }
    bool &eol()      { return _eol; }
    bool &eof()      { return _eof; }

private:
    void initialize() {
        _eol = _eof = _isAColon = badToken = false;
        _name = "";
    }

private:
    string _name;
    bool _isAColon, _eol, _eof, badToken;
};
