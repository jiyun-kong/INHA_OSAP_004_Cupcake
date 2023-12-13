/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : SungraeKim (23/11/11)
*/
#include "avl_tree.hpp"

void AvlTree::insert(const int &x) {
  root_ = recursive_insert(root_, x);
  size_++;
}

Node *AvlTree::recursive_insert(Node *node_ptr, const int &key) {
  if (node_ptr == nullptr) {
    node_ptr = new Node(key);
    return node_ptr;
  } else if (node_ptr->get_key() < key) {
    node_ptr->set_right_child(
        recursive_insert(node_ptr->get_right_child(), key));
  } else {
    node_ptr->set_left_child(recursive_insert(node_ptr->get_left_child(), key));
  }
  node_ptr->set_height(std::max(get_node_height(node_ptr->get_left_child()),
                                get_node_height(node_ptr->get_right_child())) + 1);

  rebalance_subtree(node_ptr);
  return node_ptr;
}//recursively move to a proper child position & make new node & update height & rebalance tree
