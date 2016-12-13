#ifndef TRADE_H
#define TRADE_H
#include <algorithm>
// TODO your code goes here:
//==============================================================================
template <class InputIt>
const int bestProfit( const InputIt begin, const InputIt end ) {
  // First we check if the iteration has ended or not.
  switch ( begin == end ) {
    // if so then stop the algorithm.
    case true : return 0; break;
    default : {
      // our initial value as minimum will be the first element.
      int current_minimum = *begin;
      // our profit will be Nil at this point.
      int current_profit = 0;
      // we will loop through the range and find the max and current_minimum
      std::transform(
        // we start looping from the first element
        begin,end,begin,
        // we use lambda function to find the max and current_minimum
        [&]( const int bestProfitSoFar ) {
          // Lets calculate our max value
          auto MAX = std::max( current_profit, bestProfitSoFar - current_minimum );
          // and out min value
          auto MIN = std::min(current_minimum, bestProfitSoFar);
          // we will store our current profit which will consist of the max value
          current_profit = MAX;
          // likewise, we will store the minimum value
          current_minimum = MIN;
          // we will need to return the profit as thats what we need.
          return current_profit;
        } // <= [&]lambda
      ); // <= std::transform
      // returning maximum profit
      return current_profit;
    } // <= default
  } // <= switch
} // <= bestProfit
//==============================================================================
// Don't write any code below this line
#endif
