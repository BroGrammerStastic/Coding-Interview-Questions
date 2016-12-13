## How many ways to make [2 marks]

In the file trade.h, write a function `howManyWaysToMake` that, given:

- a begin and end iterator over a range of coin sizes (with no duplicates)
- a target amount of money

... returns how many ways there are to make that amount of money, using those coins.

For instance, for iterators over the range of coin sizes `{6,2,1}` and target amount 9, your function would return 7 -- the following sums all add up to 9:

`1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1`  
`2 + 1 + 1 + 1 + 1 + 1 + 1 + 1`  
`2 + 2 + 1 + 1 + 1 + 1 + 1`  
`2 + 2 + 2 + 1 + 1 + 1`  
`2 + 2 + 2 + 2 + 1`  
`6 + 1 + 1 + 1`  
`6 + 2 + 1`  

Note:

- You don't have to return the different ways of making the amount of money, just how many there are.
- Don't count equivalent combinations more than once.  `6 + 2 + 1` is the same as `6 + 1 + 2` is the same as `1 + 2 + 6` etc.


To perform tests on your code, compile and run `testTrade.cpp`.
