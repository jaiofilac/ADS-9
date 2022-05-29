// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
    std::fstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    std::string tmp;
    while (!file.eof()) {
        char ch = file.get();
        if (ch >= 'a' && ch <= 'z') {
            tmp += ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            tmp += std::tolower(ch);
        }
        else {
            if (tmp != "") {
                tree.add(tmp);
            }
            tmp.clear();
        }
    }
    if (tmp != "") {
        tree.add(tmp);
    }
    file.close();
    return tree;
}
