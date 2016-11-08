#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:
template<typename T>
/* This class will  represent our binary tree. It will have most common
 * functionality, such as insert(), find(). This class also focuses on the law
 * of AVL trees, and its operation regarding balancing a tree that falls under
 * the expression of being "unbalanced"
 */
class BinarySearchTree {
/* Variable root, which will have a unique_ptr of a given treenode.
 * Declaired as private, this ensures that no other class can acces it
 */
private:
  unique_ptr<TreeNode<T>> root;
public:

  /* Method write() which will print our treenode.
   * Cannot be `cout` as this is printing an object
   */
  void write(std::ostream & printStream) const {
    root->write(printStream);
  }

  /* insert() method will insert a node according to its its tree.
   * It looks for an appropriate and ideal location to place our node.
   * i.e. checks for the depth of a treenode and inserts it there.
   */
  TreeNode<T> * insert ( const T & item ) {

    // lets create a treenode holding our data
    TreeNode<T> * nodeToInsert = new TreeNode<T> ( item );

    /* To insert a treenode, there are some condition that must be met before,
     * inserting. One of them is checking whether a given tree is empty or not.
     * If its empty, then theres no need to go any further, and place our node
     * to the tree, and make this node our root, since only this node exists
     */
    if ( !root.get() ) {

      /* we call the reset method which will reasign our root to be the current
       * node thats being inserted.
       */
      root.reset ( nodeToInsert );
      return nodeToInsert;
    }

    /* If the first block of if { } doesnt satisfy the current stance, we then
     * know that were not dealing with empty tree, but rather a tree that has
     * nodes in it.
     */
    TreeNode<T> * temporaryRoot = root.get();

    // now lets call checkTree() to observe even further.
    checkTree(temporaryRoot,nodeToInsert);
  }


  /* This method will observe our tree even further and compute the right
   * operation according to the current state of the tree. i.e. inserting node
   * to left or right.
   */
  TreeNode<T> * checkTree( TreeNode<T> * temporaryRoot, TreeNode<T> * nodeToInsert  ) {

    /* if the node that we are inserting has data that is smaller than the roots
     * data. Then we know we should be looking at the leftmost subtree of the
     * node.
     */
    if ( nodeToInsert->data < temporaryRoot->data ) {
      // lets visit this method which will compute the insertion
      return insertLeft(temporaryRoot, nodeToInsert);

      /* If however the data is greater than the roots data, then were dealing
       * with right most subtree.
       */
    } else if ( temporaryRoot->data < nodeToInsert->data ) {
      // lets visit this method for actual insertion
      return insertRight(temporaryRoot, nodeToInsert);
    } else {

      /* if it doesnt fall in any of the condition above, then we have a data
       * that has the exact size of the root data, we then ignore it.
       */
      return temporaryRoot;
    }
  }

  /* This method is only called when the current data is smaller than the roots
   * data.
   */
  TreeNode<T> * insertLeft(TreeNode<T> * temporaryRoot, TreeNode<T> * nodeToInsert ) {
    // Check if the left child of the current root is empty or not.
    if ( temporaryRoot->leftChild.get() == nullptr ) {

      /* This is good because, now we know that the left child is empty,
       * and so we just need to call the setLeftChild() to set the new node
       * to left.
       */
      temporaryRoot->setLeftChild ( nodeToInsert );
    } else {

      /* If its not empty, we have to traverse left, because in order to set
       * left child, we are looking for empty location.
       * to do that, we need to update the current roots location to left
       * child thats been ocupied, and then we loop again.
       */
      temporaryRoot = temporaryRoot->leftChild.get();

      // and now we need to traverse again until we have empty left child
      insertLeft(temporaryRoot,nodeToInsert);
    }

    /* So at this stage we have we set our left child. What now?
     * Now we need to deal with AVL property, and thats to balance our tree,
     * To balance our tree, we need to look if the parent of the temporary
     * root is not empty.
     * if the temporary root's parent is not empty, this is where we call
     * balance() to balance our tree.
     */
    if ( temporaryRoot->parent ) {
      balance( nodeToInsert->parent );
    }

    // lets return our nodeToInsert
    return nodeToInsert;
  }

  TreeNode<T> * insertRight(TreeNode<T> * temporaryRoot, TreeNode<T> * nodeToInsert ) {
    // Check if the left child of the current root is empty or not.
    if ( temporaryRoot->rightChild.get() == nullptr ) {

      /* This is good because, now we know that the right child is empty,
       * and so we just need to call the setRightChild() to set the new node
       * to right.
       */
      temporaryRoot->setRightChild ( nodeToInsert );
    } else {

      /* If its not empty, we have to traverse right, because in order to set
       * right child, we are looking for empty location.
       * to do that, we need to update the current roots location to right
       * child thats been ocupied, and then we loop again.
       */
      temporaryRoot = temporaryRoot->rightChild.get();

      // recursively calling itself until we get empty rightChild
      insertRight(temporaryRoot,nodeToInsert);
    }

    /* if the temporary root's parent is not empty, this is where we call
     * balance() to balance our tree.
     */
    if ( temporaryRoot->parent ) {
      balance( nodeToInsert->parent );
    }

    // lets return our nodeToInsert
    return nodeToInsert;
  }

  /* this method is called specifically for finding a particular node. This can
   * be very useful method when attmepting to insert a particular node.
   */
  TreeNode<T> * find(T newNode) {
    // lets have a temporary location of the roots TreeNode.
    TreeNode<T> * currentLocationOfRoots = root.get();
    do {
      // check if the the data that were finding is less than the roots data
      if (newNode < currentLocationOfRoots->data) {
        // if so, then assign our root to left child of the root.
        currentLocationOfRoots = currentLocationOfRoots->leftChild.get();
      } else if (currentLocationOfRoots->data < newNode) {
        // otherwise assign our root to the rightchild of the root
        currentLocationOfRoots = currentLocationOfRoots->rightChild.get();
      } else {
        // if non above, then know we have found our node, and lets return that.
        return currentLocationOfRoots;
      }
      // this will continue until the node that were traversing is not empty.
    } while(currentLocationOfRoots);
    //return nullptr;
  }

  /* This method is used for traversing from the initial location of given tree.
   */
  TreeNodeIterator<T> begin() {
    // lets have a variable thats assigned to root.
    TreeNode<T> * newRoot = root.get();
    // check whether our variable is empty first.
    if (root == nullptr ) {
      // if so, then just return empty
      return nullptr;
    } else {
      // continue to traverse until our roots left child is not empty
      do {
        // keep on assigning our roots location to the left child
        newRoot = newRoot->leftChild.get();
      } while(newRoot->leftChild.get());

      // lets create an iterator poinitng to left most treenode
      TreeNodeIterator<T> atRoot(newRoot);
      // By this line, we have the left most node. Lets assign this to iterator.
      atRoot.setRoot(root.get());
      // and return it
      return atRoot;
    }
  }

  /* This method will return our right most subtree. This method and begin()
   * method is useful for using in for loop to iterate our tree.
   */
  TreeNodeIterator<T> end() {
    // end needs to be poinitng to empty.
    return nullptr;
  }

  /*
   * ========================================
   *  Important features for AVL Trees Below
   * ========================================
   */

  /* To balance our tree, we need to somehow check which which side of the tree
   * we are looking to balance, is it left or right.
   * This computation will help us:
   * balanceFactor(node) = maxDepth(left node) - maxDepth(right node)
   */
  int balanceFactor(TreeNode<T> * node) const {
    return node->maxDepth(node->leftChild.get()) - node->maxDepth(node->rightChild.get());
  }

  /* This method will balance our tree by rotating to the right.
   */
  TreeNode<T> * rightRotation(TreeNode<T> * parent) {
    // To actually rotate, we need some nodes to clarify few issues.
    // We will need to know if the parent's parent is empty, i.e. grandParent
    TreeNode<T> * grandParent = parent->parent;

    // first check if our grandparent's parent is not empty,
    switch (grandParent->parent != nullptr) {
      case true:
      // then its easy balancing our tree
        assignGrandParentRight(grandParent,parent);
        break;
      case false:
        // if its empty, then we need to reset our parent
        resetRootRight(parent);
        break;
    }
    // lastly we need to update our current node
    updateCurrentParentRight(grandParent,parent);
  }


  /* This method will balance our tree by rotating to the left.
   */
  TreeNode<T> * leftRotation(TreeNode<T> * parent) {
    // We will need to know if the parent's parent is empty, i.e. grandParent
    TreeNode<T> * grandParent = parent->parent;
    // first check if our grandparent's parent is not empty,
    switch (grandParent->parent != nullptr) {
      case true:
      // then its easy balancing our tree
        assignGrandParentLeft(grandParent,parent);
        break;
      case false:
        // if its empty, then we need to reset our parent
        resetRootRight(parent);
        break;
    }
    // lastly we need to update our current node
    updateCurrentParentLeft(grandParent,parent);
  }


  void assignGrandParentRight(TreeNode<T> * grandParent, TreeNode<T> * parent) const {
    // empty the left child of the grandparent's parent.
    grandParent->parent->leftChild.release();
    // now lets place our new node the left child of that node.
    grandParent->parent->leftChild.reset(parent);
    // and update the parent of the current parent to the grandParent's parent.
    parent->parent = grandParent->parent;
  }

  void updateCurrentParentRight(TreeNode<T> * grandParent, TreeNode<T> * parent) {
    // empty the rightchild
    parent->rightChild.release();
    // give the new node to that right child
    parent->rightChild.reset(grandParent);
    // set the parent of grandParent to currentNode
    grandParent->parent = parent;
    // empty the left child of the grandParent
    grandParent->leftChild.release();
  }

  void assignGrandParentLeft(TreeNode<T> * grandParent, TreeNode<T> * parent) const {
    // empty the right child of the grandparent's parent.
    grandParent->parent->rightChild.release();

    // now lets place our new node the right child of that node.
    grandParent->parent->rightChild.reset(parent);

    // and update the parent of the current parent to the grandParent's parent.
    parent->parent = grandParent->parent;
  }

  void updateCurrentParentLeft(TreeNode<T> * grandParent, TreeNode<T> * parent) {
    // empty the leftchild
    parent->leftChild.release();
    // give the new node to that left child
    parent->leftChild.reset(grandParent);
    // set the parent of grandParent to currentNode
    grandParent->parent = parent;
    // empty the rightchild child of the grandParent
    grandParent->rightChild.release();
  }

  void resetRootRight(TreeNode<T> * parent) {
    // empty our root
    root.release();
    // assign the new node to the root
    root.reset(parent);
    // update the parent's parent to nullptr
    parent->parent = nullptr;
  }

  /* This method will differentiate how a tree will be balanced according
   * to its rules.
   */
  void balance(TreeNode<T> * temp) {
    // we need to check the balance factor of our root
    int balanaceFactor = balanceFactor(root.get());
    // lets compare our balance factor results
    switch (balanaceFactor) {
      // if the balanceFactor outputs 2, we need to balance our right side
      case 2:
        // if the inserted nodes parent's leftChild's rightChild is empty
        if (!temp->parent->leftChild.get()->rightChild) {
          // call the rightRotation
          temp = rightRotation(temp);
          break;
          // else if the inserted nodes parent's leftChild's leftChild is empty
        } else if (!temp->parent->leftChild.get()->leftChild) {
          // call the rightRotation
          temp = rightRotation(temp);
          break;
        }
      // if the balanceFactor is -2, we need to balance our left subtree
      case -2:
        // if the inserted nodes parent's rightChild's leftChild is empty
        if (!temp->parent->rightChild.get()->leftChild) {
          // call the leftRotation
          temp = leftRotation(temp);
          break;
          // if the inserted nodes parent's rightChild's rightChild is empty
        } else if (!temp->parent->rightChild.get()->rightChild) {
          // then call the leftRotation
          temp = leftRotation(temp);
          break;
        }
    }
  }


  /*
   * This method will return the maximum depth of given node (i.e. root)
   */
  int maxDepth() {
    return root.get()->maxDepth(root.get());
  }
};
// do not edit below this line

#endif
