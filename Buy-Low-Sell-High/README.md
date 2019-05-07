# Basic building blocks of C++

For this piece of problem, you will code using some of the basic building blocks of C++: vectors, functions, and classes.  

## The PEP vector class -- technical note

To ensure you are using `vector` correctly, for this work you will be using a version specially adapted for this assignment.  It is used by all the skeleton code provided, and involves writing:

`#include "vector.h"`  
`using pep::vector;`  

... instead of the usual:

`#include <vector>`  
`using std::vector;`  

This should not affect your solution, but note that outwith this assignment you should use the regular std vector implementation where appropriate.


# Buy low, sell high

The price of a given commodity, can be represented by a vector of prices.  For instance:

`vector<int> prices {28, 18, 20, 26, 24};`  

To maximize profit, we would want to buy low and sell high -- in this case, buy at time 1 (when the cost is 18), sell at time 3 (when the cost is 26).

In `Trade.h` implement a function `bestBuySellTime` that takes a vector of prices and returns a `Trade' object with the buy and sell time that maximises profit.  This function does not live inside any class -- it is to be defined as a global function.  *(Note that as the price vector may be large, avoid copying it within your implementation.)*

To perform some basic testing on your code, once you have implemented the function (or at least declared it) `TestTrade.cpp` defines a simple test harness.  To compile this, run:

`g++ -std=c++11 -o TestTrade TestTrade.cpp`  

If it compiles, you can then run:

`./TestTrade`  
