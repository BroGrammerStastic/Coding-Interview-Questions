#ifndef HOW_MANY_WAYS_TO_MAKE_H
#define HOW_MANY_WAYS_TO_MAKE_H
#include <iterator>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;

// TODO: Your code goes here
//==============================================================================
/**
 * ( b ) =>
 * Given a range of chnage coins and the target coin, this function will return
 * how many ways there are to make that amount of money, using those coins.
 */
template <class InputIt>
int howManyWaysToMake( InputIt begin, InputIt end, const int money ) {
  // First, lets check if there is money and our current iterator has not reached its destination
  switch (money < false || begin == end) {
    // if either is false, return nothing, as there is nothing to give change.
    case true: return false; break;
    default: {
      // so now, we will recursively call this method again, and creating somewhat branch to calc the change.
      auto callBack = howManyWaysToMake( begin , end , money - *begin ) + howManyWaysToMake( ++begin , end , money );
      // At this point, we will check, if the money is empty or not.
      switch ( money ) {
        // if so, then return true and stop recursion, as there's nothing to calculate.
        case false  : return true     ; break;
        // otherwise call the recursion again, and continuously do this.
        default     : return callBack ; break;
      } // <= switch
    } // <= default
  } // <= switch
} // <= howManyWaysToMake()
//==============================================================================
// Do not write any code below this line

#endif
