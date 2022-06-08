#include "BT.hpp" 

/*
 *Add node to binary tree (We are using special tree BST)
 */
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

/*
 *Height of the tree
 *No of nodes/edges in the longest path
 *No of edges will be less that one from no of nodes
 */
int HeightRecursive(Node* root)
{
    if (!root) {
        return (0);
    }
    return (1 + std::max(HeightRecursive(root->left), HeightRecursive(root->right)));
}
