/*
* Copyright 2023 CUPCAKE Team, Inha Univ 
* released under GPL 3.0 License
* Contributor of this file : SungraeKim (23/11/11), JiyunKong (23/11/19)
*/
#include <iostream>
#include "include/avl_tree.hpp"

using namespace std;

int main() {
  // for speeding up input, output
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  AvlTree tree;
  int T;
  cin >> T;
  for (int i=0; i<T; i++) { // repeat for test case T times
    int Q;
    cin >> Q;
    for (int j=0; j<Q; j++) { // repeat for command Q times
      string cmd;
      cin >> cmd;

      if (cmd == "minimum") {
        int node;
        cin >> node;
        tree.minimum(node);
      } else if (cmd == "maximum") {
        int node;
        cin >> node;
        tree.maximum(node);
      } else if (cmd == "empty") {
        if (tree.empty()) {
          cout << "1\n";
        } else {
          cout << "0\n";
        }
      } else if (cmd == "size") {
        cout << tree.get_size() << "\n";
      } else if (cmd == "find") {
        int node;
        cin >> node;

        cout << tree.find(node) << "\n";
      } else if (cmd == "insert") {
        int value;
        cin >> value;
        tree.insert(value);
      } 
    }
  }

  return 0;
}
