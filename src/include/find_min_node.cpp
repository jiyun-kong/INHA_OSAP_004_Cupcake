<<<<<<< HEAD
/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : BongChannavong (23/12/12)
*/

=======
>>>>>>> 0115ad8bf72d32d173b641c0d59156fd5efcb0eb
#include "avl_tree.hpp"

Node *AvlTree::find_min_node(Node* node) const {
    while (node && node->get_left_child()) {
        node = node->get_left_child();
    }
    return node;
}
