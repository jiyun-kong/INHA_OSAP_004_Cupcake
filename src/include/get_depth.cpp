/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : BongChannavong (23/11/17)
*/
#include "avl_tree.hpp"

int AvlTree::get_node_depth(Node* node_ptr) const {
    int depth = 0;
    while (node_ptr != root_) {
        node_ptr = node_ptr->get_parent();
        depth++;
    }
    return depth;
}
