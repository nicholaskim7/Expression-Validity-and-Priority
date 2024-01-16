#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include "ArgumentManager.h"
#include "Functions.h"
#include "ll.h"
using namespace std;


int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));
  
  //ifstream input("input1.txt");
  //ofstream output("output1.txt");
  
  ll list;
  string inStr; // input string 
  priority_queue<double, vector<double>, greater<double>> evals; //priority queue in ascending order

  while (getline(input, inStr)) {
  
    // Removing '\n' and '\r' from inStr
    inStr.erase(remove(inStr.begin(), inStr.end(), '\n'), inStr.end());
    inStr.erase(remove(inStr.begin(), inStr.end(), '\r'), inStr.end());

    if (validParenthesis(inStr) == false || inStr == "" || redundantBrackets(inStr) == true){
      continue;
    }
      
    else{
      // put string into postifx form
      string postfix = infixToPostfix(inStr);
      int eval = evalPostfix(postfix);
      evals.push(eval);
      list.add(inStr, eval);
    }
  }

  if(evals.empty())
    output << "No Valid Expression";
  
  while(!evals.empty()){
    list.print(output, evals.top());
    evals.pop();
  }

  return 0;
}
