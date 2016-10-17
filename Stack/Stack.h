#ifndef STACK_H
#define STACK_H

#include "vector.h"
#include <string.h>
#include <cstdlib>
#include <tuple>

using std::string;
using pep::vector;
using std::tuple;

// TODO: Your code for question 3 goes here
class Stack {
private:
  vector<double> stack;

public:
  // method used to push our node to the stack
  void push(double node) {
    stack.push_back(node);
  }

  // method used to remove the node and return it
  double pop() {
    // assign the last element in the stack to node
    double node = stack.back();
    if (!empty()) {
      // if the stack is not empty, remove it
      stack.pop_back();
    }
    // and return the node
    return node;
  }

  // boolean method that checks whether our stack is empty or not
  bool empty() const {
    if (stack.size() == 0) {
      return true;
    } else {
      return false;
    }
  }

  // return the top element of the stack
  double top()  const{
    return stack.back();
  }

  // getter method to return the stack
  vector<double> getStack() const {
    return stack;
  }

};

/*
 - function first declared before using it.
 - inline means to avoid multiple definitions.
*/
inline int evaluateRPN(vector<string> &tokens);
inline tuple<double,double> pushNodes(Stack & stack);
inline void switchStatement(Stack & stack, string getToken, double node_a, double node_b);
/*
  - this method strips the RPN string into tokens and pushed into vector.
  - calling evaluateRPN method which will return the sum of RPN in inflix mode
*/
double evaluate(string rpn) {
  // char array of our rpn
  char splitString[rpn.size() + 1];
  // Copies the string into the array
  strcpy(splitString, rpn.c_str());
  char sperate_By_Space[] = " ";
  // Our tokens
  char *token;
  // our vector which will contain our tokens
  vector<string> listOfTokens;
  // A sequence of calls to this function split str into tokens
  token = strtok( splitString, sperate_By_Space );
  // while our token is not empty
  while( token != NULL ) {
    // Push it to our vector
    listOfTokens.push_back(token);
    token = strtok( NULL, sperate_By_Space );
  }

  // calling another method which will evaluate our rpn in more details
  int sum = evaluateRPN(listOfTokens);
  return double(sum);
}

/*
  - This method when called will go through our tokens and return the sum of
  - string a and b accoridng to the operator, respectively.
*/
int evaluateRPN(vector<string> &tokens) {
  // We need our stack class to call pop and push methods
  Stack stack;
  // iterate over our tokens
  for (int i = 0; i < tokens.size(); i++) {
    string getToken = tokens[i];
    // check which operator matches our token
    if ((getToken == "+") || (getToken == "-") || (getToken == "*") || (getToken == "/")) {
      /*
        > assigning variable node_a and node_b to the top element of the stack
        > calling pop to remove the element from the stack
      */
      auto Nodes = pushNodes(stack);
      double node_a = std::get<0>(Nodes);
      double node_b = std::get<1>(Nodes);
      /*
        > Were going to compute the sum of node_a and node_b according,
        > to the operator that matches getToken[0].
        > getToken[0] = + || - || * || /
        > We'll then push the sum back to the stack
      */
      switchStatement(stack,getToken,node_a,node_b);
    } else { // push a number into the stack
      double convertToDouble = atof(getToken.c_str());
      stack.push(convertToDouble);
    }
  }
  return stack.getStack()[0];
}

/*
  - tuple that returns node a and b and being poped from the stack
*/
tuple<double,double> pushNodes(Stack & stack) {
  double node_a = stack.top();
  stack.pop();
  double node_b = stack.top();
  stack.pop();
  return std::make_tuple(node_a,node_b);
}

/*
  - according to the token that matches, it will perform its calculation
*/
void switchStatement(
  Stack & stack,
  string getToken,
  double const node_a,
  double const node_b
) {
  switch ( getToken[0] ) {
    case '+': stack.push(node_a + node_b); break;
    case '-': stack.push(node_b - node_a); break;
    case '*': stack.push(node_b * node_a); break;
    case '/': stack.push(node_b / node_a); break;
  }
}

// Do not write anything below this line

#endif
