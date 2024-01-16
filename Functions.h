#include <iostream>
#include <stack>
#include <fstream>
#include <math.h>
using namespace std;

bool isOperator(char x){
  return x == '+' || x == '-' || x == '/' || x == '*' || x == '^';
}

//michael's leetcode solution for vaild parenethesis the other causes seg fault
bool validParenthesis(string s) {
    stack<char> stack;
        
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i]) || isOperator(s[i])) continue;
          
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push(s[i]);
            }
            else if(stack.empty()){
              return false;
            }
            else if(s[i] == ')' && stack.top() == '('){
               stack.pop();
            }     
            else if(s[i] == ']' && stack.top() == '['){
               stack.pop();
            }
            else if(s[i] == '}' && stack.top() == '{'){
               stack.pop();
            }
            else{
              return false;
            }
        }            
  return stack.empty();
}

// JACOB
int priority(char c) {
  if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return 0;
}

string infixToPostfix(string s) { 
  stack<char> st;
  string postfix = "";
 
  for (int i=0; i<s.length(); i++) {
    if (isdigit(s[i])){
      postfix += s[i];
    }
      
    else if (s[i] == ' ') { 
    }
    
    else if (s[i] == '(')
      st.push('(');

    else if (s[i] == '{')
      st.push('{');

    else if (s[i] == '[')
      st.push('[');  

    else if (s[i] == ')') {
      while (st.top() != '(') {
        postfix += st.top();
        st.pop();
      }
      st.pop();
    }

    else if (s[i] == '}') {
      while (st.top() != '{') {
        postfix += st.top();
        st.pop();
      }
      st.pop();
    }

    else if (s[i] == ']') {
      while (st.top() != '[') {
        postfix += st.top();
        st.pop();
      }
      st.pop();
    }  
      
    else {
      while (!st.empty() && priority(s[i]) <= priority(st.top())) {
          postfix += st.top();
          st.pop();
      }
      st.push(s[i]);
    }
  }
  while (!st.empty()) {
    postfix += st.top();
    st.pop();
  }
  return postfix;
}

string applyOperation(int dig2, char op, int dig1) { // this and eval was given to me from workshop - Rodney (i just wanted to see if my code would give a diff output)
  if (op == '^') 
    return to_string(pow(dig2,dig1));
  else if (op == '*') 
    return to_string(dig2 * dig1);
  else if (op == '/')
    return to_string(dig2 / dig1);
  else if (op == '+')
    return to_string(dig2 + dig1);
  else if (op == '-')
    return to_string(dig2 - dig1);
  else 
    return "-1";
}

int evalPostfix(string str) {
  stack<string> s;
  int solution;
  for (int i=0;i<str.length();i++) {
    if (isdigit(str[i])) {
      string c = "";
      c += str[i];
      s.push(c);
    }
    else {
      string dig1 = s.top(); s.pop();
      string dig2 = s.top(); s.pop();
      s.push(applyOperation(stoi(dig2), str[i], stoi(dig1)));
    }
  }
  solution = stoi(s.top());
  return solution;
}

bool redundantBrackets(string expr) { // rodney
  stack<char> st;
  for (int i = 0; i < expr.length(); i++) {
    if (expr[i] == ')') {
      if (st.top() == '(')
        return true;
      while (st.top() != '(') {
        st.pop();
      }
      st.pop();
    }
    else if (expr[i] == '}') {
      if (st.top() == '{')
        return true;
      while (st.top() != '{') {
        st.pop();
      }
      st.pop();
    }
    else if (expr[i] == ']') {
      if (st.top() == '[')
        return true;
      while (st.top() != '[') {
        st.pop();
      }
      st.pop();
    }
    else
      st.push(expr[i]);
  }
  return false;
}