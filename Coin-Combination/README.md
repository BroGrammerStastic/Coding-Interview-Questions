# How many ways to make money

## Implementing `howManyWaysToMake`

In the file HowManyWaysToMake.h, write a function `howManyWaysToMake` that, given:

- an integer amount of money
- a vector of integer coin sizes available (with no duplicates)

... returns how many ways there are to make that amount of money, using those coins.

For instance, for an amount of money 9 and coin sizes `{6,2,1}` your function would return 7 -- the following sums all add up to 9:

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


To perform tests on your code, compile and run `TestCountPossiblities.cpp`.
