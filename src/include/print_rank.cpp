/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : BongChannavong (23/11/25)
*/

#include "avl_tree.hpp"
#include <iostream>

void AvlTree::print_rank(const int& key) {
    // Initialize depth and rank
    int depth = 0;
    int rank = 0;

    // Start from the root
    Node* current = root_;

    while (current != nullptr) {
        // If the key is smaller than the current node's key,
        // move to the left subtree
        if (key < current->get_key()) {
            current = current->get_left_child();
        } else if (key > current->get_key()) {
            // If the key is greater than the current node's key,
            // add the rank of the left subtree plus one, move to the right subtree, and increment depth
            rank += 1 + (current->get_left_child() != nullptr ? current->get_left_child()->get_height() : 0);
            current = current->get_right_child();
            depth++;
        } else {
            // If the key is equal to the current node's key,
            // add the rank of the left subtree and break
            rank += (current->get_right_child() != nullptr ? current->get_left_child()->get_height() : 0);
            break;
        }
    }

    std::cout << depth << " " << rank + 1 << "\n";  // Add 1 to adhere to the definition of rank (1-based index)
}


