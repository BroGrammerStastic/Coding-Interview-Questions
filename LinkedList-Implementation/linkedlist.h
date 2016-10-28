#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

// TODO your code goes here:
/*
    > a template class with generic datatype
*/
template<typename T>
// class LinkedList created
class LinkedList {
public:
  /*
    > Were going to create a "linked" list with head and tail nodes
    > We will also going to specify the size of the linked list
  */
  // first node on our linked list
  Node<T> * head;
  // last node on our linked list
  Node<T> * tail;
  // size of our linked list
  int sizeOfTheList;
  // constructor which creates an empty LinkedList with both nodes being empty
  LinkedList()
    : head(nullptr), tail(nullptr), sizeOfTheList(0) {}

    /*
      > Create a new node and insert it to the front of the list
      > This will chnage the size of the of the list, so we need to chnage the
        the tail of the list. To do that, we check if the node with next element
        is null, we inilialise the tail to that.
      @parameter, generic dataype for a node
    */
    void push_front(T pushNodeToFront) {
      // lets create a new node
      Node<T> * nextNode = new Node<T>(pushNodeToFront);
      // assign the next element to the head
      nextNode->next = head;
      // assign head with our new node
      head = nextNode;
      // assign our last node to tail
      if (head->next == nullptr) {
        tail = nextNode;
      }
    }

    /*
      > Create a new node and insert it to the back of the list
      > Like push_front(), this will change the size of the list and so we need
        to change the index of the last element.
      > First we will insert the element to the back by checking if tail = NULL
        then we add a pointer to the next as tail and update the tail to the
        new node.
    */
    void push_back(T pushNodeToBack) {
      // first lets create a new node and call it nextNode
      Node<T> * nextNode = new Node<T>(pushNodeToBack);
      // check if tail == null. If so....
      if (tail == nullptr) {
        // pointer to the next node is going to be tail now, and...
        nextNode->next = tail;
        // tail is now going to be nextNode.
        tail = nextNode;
        head = nextNode;
      }
      // if tail is not null, then next node after tail is going to be next node
      tail->next = nextNode;
      // and tail is now going to be the new node
      tail = tail->next;
    }

    /*
      > This method will return the data of the node at the front.
      > Bear in mind that each node consist of data and the address of the next
        node. So really we are calling the data of the node at the front of the
        list (aka head)
    */
    int front() {
      return head->data;
    }

    /*
      > Like front(), this method will return data of the last node
      > Our last node is called tail. So will be calling the data of the node
        which is ast the last node of the list.
    */
    int back() {
      return tail->data;
    }

    /*
      > This method is fairly simple, to get the size of the list, all we are
        going to do is iterate through the list and for each iteration, we are
        going to increment our variable. When we reach to node that is null, we
        are going to halt the iteration and return the variable
    */
    int size() {
      /*
        > this is going to be our counter which will change the value after
          every iteration
      */
      sizeOfTheList = 0;
      // lets create a node, and assign it to head, and count from there.
      Node<T> * firstNodeInTheList = head;
      // loop through the list
      do {
        /* Update the counter */
        sizeOfTheList++;
        /* now our firstNodeInTheList will be the next node in the list */
        firstNodeInTheList = firstNodeInTheList->next;
      } while(firstNodeInTheList != nullptr);
      // terminate the while loop when the next node is empty.
      // return our counter
      return sizeOfTheList;
    }

    /*
      > This method will return an iterator pointing to the head of the list
      > This is done by calling our NodeIterator class and passing our node
        which is at the front of the list (aka head).
    */
    NodeIterator<T> begin() {
      return NodeIterator<T>(head);
    }

    /*
      > very similar to begin(), this will return an iterator pointing to a
        null object in our list
    */
    NodeIterator<T> end() {
      return NodeIterator<T>(nullptr);
    }
};




// do not edit below this line

#endif
