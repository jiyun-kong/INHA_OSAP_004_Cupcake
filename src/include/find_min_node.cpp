#include "avl_tree.hpp"

Node *AvlTree::find_min_node(Node* node) const {
    while (node && node->get_left_child()) {
        node = node->get_left_child();
    }
    return node;
}
