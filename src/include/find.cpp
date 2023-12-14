/*
 * Copyright 2023 CUPCAKE Team, Inha Univ
 * released under GPL 3.0 License
 * Contributor of this file : SungraeKim (23/11/11), BongChannavong (23/11/17)
 */
#include "avl_tree.hpp"

int AvlTree::find(const int &x) {
  Node *node_ptr = root_;
  int depth = 0;
  while (node_ptr != nullptr) {
    // Check if the key of the current node matches the target value
    if (node_ptr->get_key() == x) {
      return depth;
    }
    // If the target value is greater than the key of the current node, move to the right child
    else if (node_ptr->get_key() < x) {
      node_ptr = node_ptr->get_right_child();
    }
    // If the target value is smaller than the key of the current node, move to the left child
    else {
      node_ptr = node_ptr->get_left_child();
    }
    depth++;
  }
  return 0;
}
