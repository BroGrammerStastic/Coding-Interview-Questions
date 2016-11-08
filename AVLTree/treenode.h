#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:
template<typename T>
/*
  > implemented a template class TreeNode that represents a node in a binary
    search tree.
*/
class TreeNode {
public:
  // to represent a node, we will need its data...
  T data;
  // its left child....
  unique_ptr<TreeNode> leftChild;
  // its right child...
  unique_ptr<TreeNode> rightChild;
  // and the parent of a given node
  TreeNode<T> * parent;
  // lets assign a treenode, by default the parent is empty
  TreeNode(T _data) : data(_data), parent(nullptr) {}

  // the setLeftChild will set the leftchild with the new node, by using reset()
  void setLeftChild(TreeNode<T> * child) {
    leftChild.reset(child);
    // set the parent of this left child to @this
    leftChild->parent = this;
  }

  // the setRightChild will set the rightChild with the new node, by using reset()
  void setRightChild(TreeNode<T> * child) {
    rightChild.reset(child);
    // set the parent of this left child to @this
    rightChild->parent = this;
  }

  /*
    > We need a write method which will print our data in given node.
  */
  void write(std::ostream & printStream) const {
    if (leftChild) {
      leftChild->write(printStream);
    }
    printStream << " " << data << " ";
    if (rightChild) {
      rightChild->write(printStream);
    }
  }

  int checkDepth(TreeNode<T> * root) {
    // first check if the root is empty, if so, then just return 0
    if (root == nullptr) {
      return 0;
    } else {
      // however, if not, then increment our recursive call every time
      int leftDepth =  1 + checkDepth(root->leftChild.get());
      int rightDepth = 1 + checkDepth(root->rightChild.get());

      // if either child is bigger, return it respectively
      return (leftDepth > rightDepth) ? leftDepth : rightDepth;
    }
  }

  // this method will recursive a node and will check that nodes maximum depth
  int maxDepth(TreeNode<T> * root) {
    return checkDepth(root);
  }
};

template<typename T>
class TreeNodeIterator {
  /*
   our private variables of current node and the temporary root
  */
private:
  TreeNode<T> * currentNode;
  TreeNode<T> * tmpRoot;
public:
  // it will point to the root thats passed
  TreeNodeIterator(TreeNode<T> * _currentNode)
    : currentNode(_currentNode) {}

    // A pointer operator which will return the data of the node
    T & operator*() {
        return currentNode->data;
    }

    // will check if the two nodes are the same
    bool operator==(const TreeNodeIterator& otherNode) {
      return currentNode == otherNode.currentNode;
    }

    // will check if the two nodex are not the same
    bool operator!=(const TreeNodeIterator& otherNode) {
      return currentNode != otherNode.currentNode;
    }

    /* This method will return its predecessor or successor of given root
     */
     TreeNode<T>  * predecessor_successor(
       TreeNode<T> * root,
       TreeNode<T> * predecessor,
       TreeNode<T> * successor,
       int data
     ) {
       // first, lets check if the root is empty or not
       if (root == nullptr)  return root;
       // lets check if the roots data is the same as data
       switch (root->data == data) {
         // if true
         case true:
         // then lets check if the left child is not empty
         switch (root->leftChild != NULL) {
           // if true, then....
           case true:
             // lets create a temp variable assigned to leftChild
             TreeNode<T> * tmp = root->leftChild.get();
             // while its not empty, keep on going right
             while (tmp->rightChild.get()) {
               tmp = tmp->rightChild.get();
             }
             // thats goign to be our precondition
             predecessor = tmp;
             break;
         }
         // if the right child is not empty
         switch (root->rightChild != NULL) {
           // if the true...
           case true:
             // lets get our rightChild
             TreeNode<T> * tmp = root->rightChild.get();
             // while not empty, keep on going left
             while (tmp->leftChild.get()) {
               tmp = tmp->leftChild.get();
             }
             // thats going to be our successor
             predecessor = tmp;
             break;
         }
         break;
       }
       return successor;

       // If data is smaller than root's data, go to left subtree
       switch (root->data > data) {
         case true:
           successor = root;
           predecessor_successor(root->leftChild.get(), predecessor, successor, data);
           break;
         case false:
           predecessor = root;
           predecessor_successor(root->rightChild.get(), predecessor, successor, data);
           break;
       }
     }

    // will assign the currentNode to the next node
    void operator++() {
      TreeNode<T> * predecessor, * successor;
      predecessor = successor = NULL;
      currentNode = predecessor_successor(currentNode, predecessor, successor, currentNode->data);
    }

    TreeNode<T> * setRoot(TreeNode<T> * r) {
      tmpRoot = r;
    }


};

// do not edit below this line

#endif
