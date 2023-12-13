/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : BongChannavong (23/12/12)
*/

#include "avl_tree.hpp"
#include <iostream>

void AvlTree::erase(int key) {
    int depth = find(key);  // Use find function to get the depth
    if (depth > 0) {
        root_ = erase_node(root_, key, depth);
    }
    std::cout << depth << std::endl;  // Output the depth
}

Node *AvlTree::erase_node(Node* root, int key, int& depth) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->get_key()) {
        root->set_left_child(erase_node(root->get_left_child(), key, depth));
    } else if (key > root->get_key()) {
        root->set_right_child(erase_node(root->get_right_child(), key, depth));
    } else {
        // Node found, update depth
        depth = find(root->get_key());

        // Node with only one child or no child
        if (root->get_left_child() == nullptr) {
            Node* temp = root->get_right_child();
            delete root;
            return temp;
        } else if (root->get_right_child() == nullptr) {
            Node* temp = root->get_left_child();
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node* temp = find_min_node(root->get_right_child());

        // Copy the inorder successor's data to this node
        root->set_key(temp->get_key());

        // Delete the inorder successor
        root->set_right_child(erase_node(root->get_right_child(), temp->get_key(), depth));
    }

    // Update height and balance factor
    root->set_height(std::max(get_node_height(root->get_left_child()), get_node_height(root->get_right_child())) + 1);
    int balance = get_balance_factor(root);

    // Left Left Case
    if (balance > 1 && get_balance_factor(root->get_left_child()) >= 0) {
        return rotate_right(root);
    }

    // Left Right Case
    if (balance > 1 && get_balance_factor(root->get_left_child()) < 0) {
        root->set_left_child(rotate_left(root->get_left_child()));
        return rotate_right(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance_factor(root->get_right_child()) <= 0) {
        return rotate_left(root);
    }

    // Right Left Case
    if (balance < -1 && get_balance_factor(root->get_right_child()) > 0) {
        root->set_right_child(rotate_right(root->get_right_child()));
        return rotate_left(root);
    }

    return root;
}
