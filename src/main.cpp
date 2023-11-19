/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : SungraeKim (23/11/11), JiyunKong (23/11/19)
*/
#include <iostream>
#include "include/avl_tree.hpp"

using namespace std;

int main() {
  AvlTree tree;

  // test if the tree is empty
  if (tree.empty()) {
    cout << "The tree is empty.\n";
  } else {
    cout << "The tree is not empty.\n";
  }

  // insert data
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);

  // find value
  if (tree.find(30)) {
    cout << "30 found in the tree\n";
  } else {
    cout << "30 not found in the tree\n";
  }

  // get size
  cout << "Size of the tree : " << tree.get_size() << "\n";

  // test if the tree is empty
  if (tree.empty()) {
    cout << "The tree is empty.\n";
  } else {
    cout << "The tree is not empty.\n";
  }

  // get minimum
  tree.minimum(20);

  // get maximum
  tree.maximum(20);

  return 0;
}
