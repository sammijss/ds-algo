#ifndef _BT_H_
#define _BT_H_

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

int   HeightRecursive(Node* root);

void  PreorderTraverseRecursive(Node* root);    //DFS
void  InorderTraverseRecursive(Node* root);     //DFS
void  PostorderTraverseRecursive(Node* root);   //DFS

void  LevelOrderTraverseUsingHeightRecursive(Node* root);  //BFS
void  LevelOrderTraverseUsingQueueRecursive(Node* root);  //BFS

void  LeftViewOfTreeUsingHashMapRecursive(Node* root);
void  RightViewOfTreeUsingHashMapRecursive(Node* root);

void  LeftViewOfTreeUsingQueueRecursive(Node* root);
void  RightViewOfTreeUsingQueueRecursive(Node* root);

#endif
