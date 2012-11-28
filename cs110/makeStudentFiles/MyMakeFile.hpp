#include<iostream>
#include<string>

using namespace std;

class MyMakefile {
public:
    MyMakefile( string name ): fileToMake( name ), targetToMake(""), tree(0) {}
    void print();
    void ParseMakefile();
    void runMake();

private:
    bool isCyclic();

private:
    string fileToMake, targetToMake;
    MakeTree *tree;
};
