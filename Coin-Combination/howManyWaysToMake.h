#ifndef HOW_MANY_WAYS_TO_MAKE_H
#define HOW_MANY_WAYS_TO_MAKE_H

#include <vector>
using std::vector;

// TODO: Your answer for question 1a goes here
/*
  - This method, when called will return vector of ints with the exception
  - of the first element
*/
vector<int> getCoinSizeWithoutFirstElement(vector<int> const _callingVectorOfCoins) {
  vector<int> arrayOfCoins;
  int i = 0;
  while (++i < _callingVectorOfCoins.size()) {arrayOfCoins.push_back(_callingVectorOfCoins[i]);}
  return arrayOfCoins;
}

/**
  - This method will return how many ways we can make for the sum
**/
int howManyWaysToMake(const int money, vector<int> const _callingVectorOfCoins) {
  // initialise howManyWays to 0, as at this stage, its nothing
  int howManyWays = false;
  // check if the vector contains any element
  if (_callingVectorOfCoins.size() == true) {
    // if the remainder of the money is 0, return 1;
    if (money % _callingVectorOfCoins[false] == false) {return 1;}
    else {return false;}
  } else {
    // if the vector contains any values, call the method to return vector,
    // excluding the first element
    vector<int> cointSizeWithoutFirst = getCoinSizeWithoutFirstElement(
      _callingVectorOfCoins
    );
    int i = 0;
    do {
      // recursive calling the method, with each iteration, decreasing  the
      // money by the iteration number
      int callBack = howManyWaysToMake(
        money - i * _callingVectorOfCoins[0],
        cointSizeWithoutFirst
      );
      // for each recurive call, we will increment our ways, as for each
      // call made, we assume there is one of way of equallign to the sum
      howManyWays += callBack;
      i++;
      // exit the while loop when i x element at 0 is greater than money
    } while((i * _callingVectorOfCoins[0]) <= money);
  }
  // return our variable
  return howManyWays;
}
// Do not write any code below this line

#endif
