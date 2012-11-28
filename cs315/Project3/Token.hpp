#ifndef TOKEN_HPP
#define TOKEN_HPP

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
    bool &isATab()   { return _isATab; }
    bool &eol()      { return _eol; }
    bool &eof()      { return _eof; }
    bool &badToken() { return _badToken; } 

private:
    void initialize() {
        _eol = _eof = _isAColon = _isATab = _badToken = false;
        _name = "";
    }
    int toInt( bool b ) { return b; }

private:
    string _name;
    bool _isAColon, _isATab, _eol, _eof, _badToken;
};

#endif
