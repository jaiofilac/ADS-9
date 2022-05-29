// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
public:
    struct Node {
        T data;
        int count;
        Node* right;
        Node* left;
    };

private:
    Node* root;
    Node* addNode(Node* localRoot, T data) {
        if (localRoot == nullptr) {
            localRoot = new Node;
            localRoot->data = data;
            localRoot->count = 1;
            localRoot->left = localRoot->right = nullptr;
        } else if (localRoot->data.compare(data) > 0) {
            localRoot->left = addNode(localRoot->left, data);
        } else if (localRoot->data.compare(data) < 0) {
            localRoot->right = addNode(localRoot->right, data);
        } else {
            localRoot->count++;
        }
        return localRoot;
    }
    int depthTree(Node* localRoot) {
        if (localRoot == nullptr) {
            return 0;
        } else {
            int l = depthTree(localRoot->left);
            int r = depthTree(localRoot->right);
            return 1 + (l >= r ? l : r);
        }
    }
    int searchNode(Node* localRoot, T data) {
        int check = localRoot->data.compare(data);
        if (check == 0) {
            return localRoot->count;
        } else if (check > 0) {
            if (localRoot->left != nullptr) {
                return searchNode(localRoot->left, data);
            }
            return 0;
        } else {
            if (localRoot->right != nullptr) {
                return searchNode(localRoot->right, data);
            }
            return 0;
        }
    }
    void delTree(Node* localRoot) {
        if (localRoot == nullptr) {
            return;
        } else {
            delTree(localRoot->left);
            delTree(localRoot->right);
            delete localRoot;
        }
    }
    Node* delNode(Node* localRoot, T data) {
        Node* p, * v;
        if (localRoot == nullptr) {
            return localRoot;
        } else if (localRoot->value.compare(data) > 0) {
            localRoot->left = delNode(localRoot->left, data);
        } else if (localRoot->value.compare(data) < 0) {
            localRoot->right = delNode(localRoot->right, data);
        }  else {
            p = localRoot;
            if (localRoot->right == nullptr) {
                localRoot = localRoot->left;
            } else if (localRoot->left == nullptr) {
                localRoot = localRoot->right;
            } else {
                v = localRoot->left;
                if (v->right) {
                    while (v->right->right)
                        v = v->right;
                    localRoot->value = v->right->value;
                    localRoot->count = v->right->count;
                    p = v->right;
                    v->right = v->right->left;
                } else {
                    localRoot->value = v->value;
                    localRoot->count = v->count;
                    p = v;
                    localRoot->left = localRoot->left->left;
                }
            }
            delete p;
        }
        return localRoot;
    }

public:
    BST() : root(nullptr) {}
    void add(T data) {
        root = addNode(root, data);
    }
    int depth() {
        if (root) {
            return depthTree(root) - 1;
        }
        return 0;
    }
    int search(T data) {
        return searchNode(root, data);
    }
    void clear() {
        if (root) {
            delTree(root);
            root = nullptr;
        }
    }
    void remove(T data) {
        if (root)
            root = delNode(root, data);
    }
};

#endif  // INCLUDE_BST_H_
