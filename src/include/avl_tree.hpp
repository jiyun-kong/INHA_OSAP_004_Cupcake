#ifndef INHA_OSAP_004_CUPCAKE_INCLUDE_AVL_TREE_H
#define INHA_OSAP_004_CUPCAKE_INCLUDE_AVL_TREE_H

class Node {
  int key;
  int ballance_factor;
  int height;
  Node *parent = nullptr;
  Node *left_child = nullptr;
  Node *right_child = nullptr;
};

class AvlTree {
private:
  Node *root_;
  int size_;

public:
  AvlTree() : size_(0), root_(nullptr){};
  void
  minimum(int x); // print key and depth values of the node which has minimum
                  // key in the subtree of given node via standard output
  void
  maximum(int x); // print key and depth values of the node which has maximum
                  // key in the subtree of given node via standard output
  bool empty();
  int size();
  int find(int x); //
  void insert(int x);
};

#endif