#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H


#include "vector.h"
using pep::vector;

/** TODO: complete the definition of the class CircularBuffer here
 *
 * Its constructor should take the size of the buffer as an argument
 *
 * It needs to have the functions:
 * - count() which returns how many things are in the buffer
 * - full() which returns true iff the buffer is full
 * - add() which takes an element and adds it to the buffer (you can assume the buffer is not full)
 * - remove() which removes the next element from the buffer (you can assume the buffer is not empty)
 */
class CircularBuffer {
/*
  - Few private variables declaired
*/
private:
  vector<char> buf;
  int front;
  int rear;

protected:
  int memory;


/*
  - constrcutor constructed with memorySize as the argument
  - assigning front and back of the array to -1
*/
public:
  CircularBuffer(const int memorySize)
  :buf(memorySize), front(-1), rear(-1) {

  }

  // Getter method for retrieving memory size
  int getMemory() const{
    return memory;
  }

  /*
    - method which returns how many elements exists within vector
  */
  int count() const {
    int returnVal,charCount;
    charCount = 0;
    for (int i = 0; i < buf.size(); i++) {
      if (buf.size() == 0) {
        returnVal = 0;
      } else if (buf[i] != 0) {
        charCount++;
      }
      returnVal = charCount;
    }
    return returnVal;
  }

  /*
    - add method which add the char to the end of the array and increases the size
  */
  void add(char c) {
    if (front == -1 && rear == -1) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % buf.size();
    }
    buf[rear] = c;
  }


  /*
    - remove method which removes the char from the top of the array
  */
  char remove() {
    char returnValue;
    if (front == rear) {
      returnValue = buf[rear];
      rear = front = -1;
    } else {
      returnValue = buf[front];
      front = (front + 1) % buf.size();
    }
    return returnValue;
  }

  /*
    - method which checks if the vector is empty or not
  */
  bool full() {
    return (rear + 1) % buf.size() == front ? true : false;
  }
};


// don't write any code below this line

#endif
