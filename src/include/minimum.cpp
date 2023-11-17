/*
 * Copyright 2023 CUPCAKE Team, Inha Univ
 * released under GPL 3.0 License
 * Contributor of this file : SungraeKim (23/11/11), BongChannavong (23/11/17)
 */

#include "avl_tree.hpp"
#include <iostream> 

void AvlTree::minimum(const int &x) { // Define the minimum function that takes an integer reference as input
  Node *node_ptr = root_; // Initialize a pointer to the root node of the AVL tree
  while (node_ptr != nullptr) { // Iterate until the node pointer is not null
    if (node_ptr->get_key() == x) { // Check if the key of the current node is equal to the input value
      std::cout << node_ptr->get_key() << " " << get_node_depth(node_ptr) << std::endl; // Print the key of the current node
      return;
    } else if (node_ptr->get_key() < x) { // Check if the key of the current node is less than the input value
      node_ptr = node_ptr->get_right_child(); // Move to the right child of the current node
    } else { 
      node_ptr = node_ptr->get_left_child(); // Move to the left child of the current node
    }
  }
}
