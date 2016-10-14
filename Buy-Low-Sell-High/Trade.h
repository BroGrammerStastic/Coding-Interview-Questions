#ifndef TRADE_H
#define TRADE_H


#include "vector.h"
using pep::vector;


class Trade {
  /*
    Comment: {
      - Some protected variables declaired above the class
    };
      @default state: declaired
      @return       : Nothing
  */
protected:
    int buyTime;
    int sellTime;

/*
  Comment: {
    - a constructor initialised with two arguments
    - initilaised the two protected variables above to the argument passed
    - getter() method created
  };
==========================
@default state: declaired
@return       : Nothing
*/
public:
    Trade(const int buyTimeIn, const int sellTimeIn)
        : buyTime(buyTimeIn), sellTime(sellTimeIn) {
    }

    int getBuyTime() const {
        return buyTime;
    }

    int getSellTime() const {
        return sellTime;
    }

};

// TODO your code goes here:

/*
  Comment: {
    - A method that returns the min and max value with the highest profit
    - two for loops {
          > one for loop gets the minium value
          > and the other gets the maximum value
      }
    - an if statement that checks if the profit is high
  };
==========================
@return: (minimum value index,maximum value index)
*/
Trade bestBuySellTime(pep::vector<int>& vec) {
  // some variables initialised with index outside of the array (i.e. -1)
  int min = 0;
  int minIndex = -1;
  int maxIndex;

  /*
    - get the minimum value, but also ensuring the
    - minimum value is before the last index
  */
  for (int i = 0; i < vec.size(); i++) {
    if (i != vec.size() -  1) {
      if (!min || vec[i] < min) {
        min = vec[i];
        minIndex = i;
      }
    }
  }

  /*
    - get the maximum value after the min value index.
  */
  if (min != -1) {
    int max = min;
    for (int i = minIndex + 1 ; i < vec.size() ; i++) {
      if (vec[i] > max) {
        max = vec[i];
        maxIndex = i;
      }
    }

    // if there is no maximum value after the min value, then return 0
    for (int i = max; i < vec.size() ; i++) {
      if ( !(vec[i] > max) ) {
        minIndex = 0;
        maxIndex = 0;
      }
    }
  }
  return Trade(minIndex,maxIndex);
}
// Don't write any code below this line

#endif
