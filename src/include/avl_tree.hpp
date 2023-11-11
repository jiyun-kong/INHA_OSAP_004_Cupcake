#ifndef INHA_OSAP_004_CUPCAKE_SRC_INCLUDE_AVL_TREE_H
#define INHA_OSAP_004_CUPCAKE_SRC_INCLUDE_AVL_TREE_H

#include <algorithm>

class Node {
private:
  int key_;
  int height_;
  Node *parent_;
  Node *left_child_;
  Node *right_child_;

public:
  Node(const int &key)
      : key_(key), height_(0), parent_(nullptr), left_child_(nullptr),
        right_child_(nullptr) {}

  int get_key() const { return key_; }
  int get_height() const { return height_; } // may not use in AvlTree. Instead, use get_node_height declared in AvlTree
  void set_height(const int &height) { height_ = height; }
  Node *get_parent() const { return parent_; }
  void set_parent(Node *parent) { parent_ = parent; }
  Node *get_left_child() const { return left_child_; }
  void set_left_child(Node *left_child) { left_child_ = left_child; }
  Node *get_right_child() const { return right_child_; }
  void set_right_child(Node *right_child) { right_child_ = right_child; }
};

class AvlTree {
private:
  Node *root_;
  int size_;

  int get_node_height(Node *node_ptr) const;
  int get_balance_factor(Node *node_ptr) const; //caculate balance factor of given node
  Node *recursive_insert(Node *node_ptr, const int &key); //recursively move to a proper child position & make new node & update height & rebalance tree
  void rebalance(Node* &node_ptr,const int& key); //rebalance subtree in LL,LR,RL,RR cases 
  Node *rotate_left(Node *center_node);
  Node *rotate_right(Node *center_node);

public:
  AvlTree() : size_(0), root_(nullptr) {}
  int get_size() const { return size_; }
  void minimum(
      const int &x); // print key and depth values of the node which has minimum
                     // key in the subtree of given node via standard output
  void maximum(
      const int &x); // print key and depth values of the node which has maximum
                     // key in the subtree of given node via standard output
  bool empty();

  int find(const int &x); // return depth of node with given key. If not exist,
                          // return 0
  void insert(const int &x);
};

#endif