# Important note

Because this work is asking you to write code in a functional programming style, then unless a part of a question says otherwise, I do not want you to write loops in a standard imperative programming style.  That is, the following are all forbidden:

- `for`, `while`, `do..while`
- The `for_each` function in the `<algorithm>` header file
- Anything that fakes one of the above (e.g. a combination of `if` and `goto`)

It is expected, instead, that you will use the `<algorithm>` or `<numeric>` functions such as those discussed in the lecture.

A mark of zero will be awarded for any parts of questions breaking this rule.

## Trade [3 marks]

The price of a given commodity, can be represented by a vector of prices.  For instance:

`vector<int> prices {28, 18, 20, 26, 24};`  

To maximise profit, we would want to buy low and sell high -- in this case, buy at time 1 (when the cost is 18), sell at time 3 (when the cost is 26).

In `trade.h` define a template function `bestProfit` that takes two iterators, denoting the begin() and end() of a range of prices, and returns an integer denoting the best profit that could be made (for the example above: 8).

*Note: as with part (a), imperative loops are forbidden, and you must not write any functions other than `bestProfit`.*
