#ifndef TREEMAP_H
#define TREEMAP_H

#include "tree.h"

template<typename Key, typename Value>
/*
  > Our treemap will consist of value pairs
*/
class KeyValuePair {

public:
  // we need a key
  const Key k;
  // and its value
  Value v;
  // constructor that holds key and value
  KeyValuePair(Key _key, Value _value) : k(_key), v(_value) {}
  // another constructor that holds just the key
  KeyValuePair(Key _key) : k(_key) {}
  // TODO your code for KeyValuePair goes here
  // we have an operator that checks of the key of this KeyValuePair is smaller
  // than another KeyValuePair
  bool operator<(const KeyValuePair & otherKeyValuePair) const {
    return (k < otherKeyValuePair.k);
  }
};

template<typename Key, typename Value>
// an ostream that prints the key and its value
ostream & operator<<(ostream & o, const KeyValuePair<Key,Value> & kv) {
    o << kv.k << "," << kv.v;
    return o;
}

template<typename Key, typename Value>
/*
  A class that holds TreeMap
*/
class TreeMap {
private:
  // this class will hold BinarySearchTree of KeyValuePair
  BinarySearchTree<KeyValuePair<Key,Value>> tree;
public:
  // an insert method that adds a KeyValuePair to a binary search tree.
  KeyValuePair<Key,Value> * insert(const Key & k, const Value & v) {
    // once inserted, return it...
    return &(tree.insert(KeyValuePair<Key,Value>(k,v))->data);
  }

  // this method will print our tree
  void write(ostream & o) const {
    tree.write(o);
  }

  // find method that search for a specific KeyValuePair
  KeyValuePair<Key,Value> * find(const Key k) {
    KeyValuePair<Key,Value> a(k);
    return (tree.find(a)) ? &(tree.find(KeyValuePair<Key,Value>(k))->data) : nullptr;
  }
    // TODO your code for TreeMap goes here:
};


// do not edit below this line

#endif
