/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : SungraeKim (23/11/11)
*/
#include <iostream>
#include "avl_tree.hpp"

using namespace std;

int main() {
    AvlTree test;
    test.insert(4);
    test.insert(6);
    test.insert(7);
    test.insert(3);
    test.find(7);
}