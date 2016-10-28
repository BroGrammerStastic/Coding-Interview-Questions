#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

// TODO your code for the Node class goes here:
// (Note the 'NodeIterator' class will report lots of errors until Node exists
template<typename T>
/*
This clss creates a node with prev and next as empty
*/
class Node {
public:
/*
  > data is stored on non-contiguous bloks of memory, and we call each block of
    memory a node.
  > each node has two parts, one that stores the data, and the other that stores
    the address of the next node
*/
  T data;               // So we have data of any type
  Node<T> * next;       // a node that we call next
  Node<T> * previous;   // another node that we call previous
  // constructor that takes data of any type
  Node(T _data)
  // initialise the data to the the param, and th next two nodes to null
  : data(_data), next(nullptr), previous(nullptr) {}
};

template<typename T>
/*
  > We have a class nodeiterator that iterates over our node list
*/
class NodeIterator {
private:
    // we are going to call the current node
    Node<T>* currentNode;
public:
    // the nodeiterator takes a node pointer
    NodeIterator(Node<T> * currentIn)
        // initialises it to the current node
        : currentNode(currentIn) {
    }
    // '->' is returning data of the node pointer. Simialr concept with '.'
    T & operator*() {
        return currentNode->data;
    }
    // TODO: complete the code for NodeIterator here

    // will assign the currentNode to the next node
    void operator++() {
      currentNode = currentNode->next;
    }

    // will check if the two nodes are the same
    bool operator==(const NodeIterator& otherNode) {
      return currentNode == otherNode.currentNode;
    }

    // will check if the two nodex are not the same
    bool operator!=(const NodeIterator& otherNode) {
      return currentNode != otherNode.currentNode;
    }

};

// do not edit below this line

#endif
