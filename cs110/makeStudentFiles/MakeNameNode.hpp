#include<iostream>
#include<string>
#include<vector>

using namespace std;

class MakeNameNode {
public:
    MakeNameNode( string name ): _name( name ), _timeStamp(0), _command(""), _target(false), _visited(false) {}
    string &name() { return _name; }
    int &timeStamp() { return _timeStamp; }
    vector<MakeNameNode *> &getAdjVector();
    string &command() { return _command; }
    void runCommand();  // execute the command associated with this node.
    bool isATarget();
    void print();

private:
    string _name;
    int _timeStamp;
    std::vector<MakeNameNode *> dependencyList;
    string _command;
    bool _target;
    bool _visited;
};
