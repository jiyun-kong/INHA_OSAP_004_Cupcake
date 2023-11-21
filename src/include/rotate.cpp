/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : SungraeKim (23/11/11)
*/
#include "avl_tree.hpp"

// do not change order of comparement conditions to prevent accessing null
// pointer

void AvlTree::rebalance_subtree(Node*& node_ptr) {
    int balance_factor = get_balance_factor(node_ptr);

    // LL case
    if (balance_factor > 1 && get_node_height(node_ptr->get_left_child()->get_left_child()) >= get_node_height(node_ptr->get_left_child()->get_right_child())) {
        node_ptr = rotate_right(node_ptr);
    }

    // LR case
    else if (balance_factor > 1 && get_node_height(node_ptr->get_left_child()->get_left_child()) < get_node_height(node_ptr->get_left_child()->get_right_child())) {
        node_ptr->set_left_child(rotate_left(node_ptr->get_left_child()));
        node_ptr = rotate_right(node_ptr);
    }

    // RL case
    else if (balance_factor < -1 &&
        get_node_height(node_ptr->get_right_child()->get_right_child()) < get_node_height(node_ptr->get_right_child()->get_left_child())) {
        node_ptr->set_right_child(rotate_right(node_ptr->get_right_child()));
        node_ptr = rotate_left(node_ptr);
    }

    // RR case
    else if (balance_factor < -1 && get_node_height(node_ptr->get_right_child()->get_right_child()) >= get_node_height(node_ptr->get_right_child()->get_left_child())) {
        node_ptr = rotate_left(node_ptr);
    }
}//rebalance subtree in LL,LR,RL,RR cases 

Node *AvlTree::rotate_left(Node *center_node) {
  Node *rotating_node = center_node->get_right_child();
  center_node->set_right_child(rotating_node->get_left_child());
  rotating_node->set_left_child(center_node);

  center_node->set_height(
      std::max(get_node_height(center_node->get_left_child()),
               get_node_height(center_node->get_right_child())) +
      1);
  rotating_node->set_height(
      std::max(get_node_height(rotating_node->get_left_child()),
               get_node_height(rotating_node->get_right_child())) +
      1);

  return rotating_node;
}

Node *AvlTree::rotate_right(Node *center_node) {
  Node *rotating_node = center_node->get_left_child();
  center_node->set_left_child(rotating_node->get_right_child());
  rotating_node->set_right_child(center_node);

  center_node->set_height(
      std::max(get_node_height(center_node->get_left_child()),
               get_node_height(center_node->get_right_child())) +
      1);
  rotating_node->set_height(
      std::max(get_node_height(rotating_node->get_left_child()),
               get_node_height(rotating_node->get_right_child())) +
      1);

  return rotating_node;
}