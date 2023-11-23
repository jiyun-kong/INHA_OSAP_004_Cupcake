/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : SungraeKim (23/11/11), BongChannavong (23/11/17), JiyunKong (23/11/21)
*/
#include "avl_tree.hpp"
#include <iostream> 

using namespace std;

void AvlTree::maximum(const int& x){ 
    Node* node_ptr = root_; 
    while (node_ptr != nullptr && node_ptr->get_key() != x) { // Loop until the node pointer is not null
        if (node_ptr->get_key() < x) { // Check if the key of the current node is less than the input value
            node_ptr = node_ptr->get_right_child(); // Move to the right child of the current node
        } else { 
            node_ptr = node_ptr->get_left_child(); // Move to the left child of the current node
        }
    }

    if (node_ptr == nullptr) {
        return;
    }

    // Find the right node in the subtree which has the maximum key
    while (node_ptr -> get_right_child() != nullptr) {
        node_ptr = node_ptr->get_right_child();
    }

    cout << node_ptr->get_key() << " " << find(node_ptr->get_key())<< "\n";
}
