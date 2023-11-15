/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : SungraeKim (23/11/11)
*/
#include "avl_tree.hpp"

int AvlTree::get_node_height(Node *node_ptr) const {
  if (node_ptr == nullptr)
    return -1;
  else
    return node_ptr->get_height();
} // Consider nullptr case

int AvlTree::get_balance_factor(Node *node_ptr) const {
  return get_node_height(node_ptr->get_left_child()) -
         get_node_height(node_ptr->get_right_child());
}//caculate balance factor of given node