# Using stacks

In `Stack.h`, implement a class `Stack` that is a Stack of `double`s.  You should implement this using the provided vector class: Stack.h contains the necessary `include` and `using` lines for this.

Your `Stack` class needs to provide three functions:

- `empty()` that returns true if the stack is empty
- `pop()` that removes and returns the top element off the stack
- `push()` that takes a double and pushes it onto the stack

Once you have written a Stack class, after it -- but still in `Stack.h` -- implement a function `evaluate` that takes a string containing a mathematical expression written in [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation), and returns the result of evaluating the expression.

In reverse polish notation (RPN), operators are written *after* rather than between what they act upon.  For instance:

`3.0 4.0 +`

...is the same as the usual (infix) notation `(3.0 + 4.0)`.  Or:

`3.0 4.0 + 2.0 *`

...is the same as `(3.0 + 4.0) * 2`.  The advantage of RPN is that there is no need to worry about brackets and order of precedence.

To implement the `evaluate` function, use your Stack class.  RPN expressions can be evaluated by splitting the input string by spaces into tokens, and working through it one token at a time:

 * If the token is a `+`, pop two numbers a and b off the stack, and push (b + a) onto the stack
 * If the token is a `-`, pop two numbers a and b off the stack, and push (b + a) onto the stack
 * If the token is a `*`, pop two numbers a and b off the stack, and push (b * a) onto the stack
 * If the token is a `/`, pop two numbers a and b off the stack, and push (b / a) onto the stack
 * Otherwise, the token is a number: push it onto the stack

 After going through all the tokens, the answer is then on the top of the stack: return it.

 To test your code, compile and run `TestStack.cpp`.  This will to evaluate three expressions, and check they give the right answer.
