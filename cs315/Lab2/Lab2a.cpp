/*
Lab2a.cpp
Eric Brewer
9/9/09
Lab2 - Postfix arithmetic expressions.
*/

#include <vector>
#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  vector<int> numStack;
  vector<string> fullExpr;
  string dud = "";
  int result = 0;
  bool noInput = true;

  do{
    cout << "Enter a valid postfix expression: ";
    while(cin.peek() != '\n'){
      cin >> dud;
      fullExpr.push_back(dud);
    }
    noInput = fullExpr.empty();
    if(!noInput){
      for(int i = 0; i < fullExpr.size(); i++){
	if(fullExpr[i] == "+"){
	  result = numStack[numStack.size()-2] + numStack.back();
	  numStack.pop_back();
	  numStack.pop_back();
	  numStack.push_back(result);
	}
	else if(fullExpr[i] == "-"){ 
	  result = numStack[numStack.size()-2] - numStack.back();
	  numStack.pop_back();
	  numStack.pop_back();
	  numStack.push_back(result);
	}
	else if(fullExpr[i] == "*"){ 
	  result = numStack[numStack.size()-2] * numStack.back();
	  numStack.pop_back();
	  numStack.pop_back();
	  numStack.push_back(result);
	}
	else if(fullExpr[i] == "/"){ 
	  result = numStack[numStack.size()-2] / numStack.back();
	  numStack.pop_back();
	  numStack.pop_back();
	  numStack.push_back(result);
	}
	else if(fullExpr[i] == "%"){ 
	  result = numStack[numStack.size()-2] % numStack.back();
	  numStack.pop_back();
	  numStack.pop_back();
	  numStack.push_back(result);
	}
	else 
	  numStack.push_back(atoi(fullExpr[i].c_str()));
      }
      for(int i = 0; i < fullExpr.size(); i++)
	cout << fullExpr[i] << " ";
      cout << "= " << numStack.back() << endl;
      
      fullExpr.clear();
      numStack.clear();
      dud = "";
      result = 0;
    }
  }while(!noInput && cin.peek() != '\n');
  
  return 0;
}
