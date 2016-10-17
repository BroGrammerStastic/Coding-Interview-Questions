#ifndef MAXIMUM_GATES_H
#define MAXIMUM_GATES_H

#include <vector>
using std::vector;

// TODO: Your answer for question 2 goes
/**
  - We first set our maximum gates to the number of elements of arrivals.
  - We can then assume that this will be our maximum gates.
  - We then go through our departure array and check,
  - if the the i at departs[i] is smaller than the arrival of the next plain
  - If sove is true, we decrement the number of gates
**/
int  maximumGates( const vector<int> & arrives, const vector<int> & departs ) {
  int numberOfGates,closestVal,i;
  numberOfGates = arrives.size();
  i = 0;
  int j = 1;
  do {
    if (departs[i] < arrives[j]) {
      numberOfGates--;
    }
  }
  while((++i < departs.size()) && (++j < arrives.size())  );
  return numberOfGates;
}
// Do not write any code below this line


#endif
