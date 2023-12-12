/*
 * Copyright 2023 CUPCAKE Team, Inha Univ
 * released under GPL 3.0 License
 * Contributor of this file : BongChannavong (12/12/17)
 */

#include "avl_tree.hpp"

void AvlTree::erase(int key) {
    int depth = 0;  // Initialize depth
    root_ = eraseNode(root_, key, depth);
    std::cout << depth << std::endl;  // Output the depth
}

AvlTree::Node* AvlTree::eraseNode(Node* root, int key, int& depth) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->get_key()) {
        root->set_left_child(eraseNode(root->get_left_child(), key, depth));
    } else if (key > root->get_key()) {
        root->set_right_child(eraseNode(root->get_right_child(), key, depth));
    } else {
        // Node found, update depth
        depth = root->getDepth();

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
        Node* temp = minValueNode(root->get_right_child());

        // Copy the inorder successor's data to this node
        root->set_key(temp->get_key());

        // Delete the inorder successor
        root->set_right_child(eraseNode(root->get_right_child(), temp->get_key(), depth));
    }

    // Update height and balance factor
    root->updateHeight();
    int balance = root->getBalance();

    // Left Left Case
    if (balance > 1 && root->get_left_child()->getBalance() >= 0) {
        return rotateRight(root);
    }

    // Left Right Case
    if (balance > 1 && root->get_left_child()->getBalance() < 0) {
        root->set_left_child(rotateLeft(root->get_left_child()));
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && root->get_right_child()->getBalance() <= 0) {
        return rotateLeft(root);
    }

    // Right Left Case
    if (balance < -1 && root->get_right_child()->getBalance() > 0) {
        root->set_right_child(rotateRight(root->get_right_child()));
        return rotateLeft(root);
    }

    return root;
}

AvlTree::Node* AvlTree::minValueNode(Node* node) {
    Node* current = node;
    while (current->get_left_child() != nullptr) {
        current = current->get_left_child();
    }
    return current;
}
