/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : SungraeKim (23/11/11)
*/
#include "avl_tree.hpp"

bool AvlTree::empty() {
  return this->size_==0;
} // return true if size_ is equal to 0