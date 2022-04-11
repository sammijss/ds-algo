#include <stack> 
#include "BST.hpp" 

Node* AddNode(Node* root, int data) {
    if (!root) {
        return (new Node(data));
    }
    
    if (root->data > data) {
            root->left = AddNode(root->left, data);
    }
    else {
            root->right = AddNode(root->right, data);
    }
    return root;
}

