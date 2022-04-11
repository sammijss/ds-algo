#ifndef _BST_H_
#define _BST_H_

#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/*
 * APIs
 */
Node* AddNode(Node* root, int data);

#endif
