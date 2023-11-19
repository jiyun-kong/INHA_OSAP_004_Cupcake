/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : SungraeKim (23/11/11), BongChannavong (23/11/17)
*/
#include "avl_tree.hpp"
#include <iostream> 

void AvlTree::maximum(const int &x) {
    // Find the node with the given key in the subtree rooted at x
    Node *current = root_;
    while (current != nullptr && current->get_key() != x) {
        if (x < current->get_key()) {
            current = current->get_left_child();
        } else {
            current = current->get_right_child();
        }
    }

    if (current == nullptr) {
        return;
    }

    // Find the maximum key in the subtree rooted at the current node
    while (current->get_right_child() != nullptr) {
        current = current->get_right_child();
    }

    // Print key and depth values of the node
    std::cout << current->get_key() << " " << get_node_depth(current) << std::endl;
}
