#include <queue> 
#include <unordered_map> 
#include "BT.hpp" 

/*
 *Pre-order traversal
 */
void PreorderTraverseRecursive(Node* root) {
    if (!root) {
        return;
    }
    std::cout <<root->data <<" ";
    PreorderTraverseRecursive(root->left);
    PreorderTraverseRecursive(root->right);
}

/*
 *In-order traversal
 */
void InorderTraverseRecursive(Node* root) {
    if (!root) {
        return;
    }
    InorderTraverseRecursive(root->left);
    std::cout <<root->data <<" ";
    InorderTraverseRecursive(root->right);
}

/*
 *Post-order traversal
 */
void PostorderTraverseRecursive(Node* root) {
    if (!root) {
        return;
    }
    PostorderTraverseRecursive(root->left);
    PostorderTraverseRecursive(root->right);
    std::cout <<root->data <<" ";
}

/*
 *Print the node at given level
 */
static void PrintNodeGivenLevel(Node* root, int level) {
    if (!root) {
        return;
    }
    if (level == 1) {
        std::cout <<root->data <<" ";
    }
    if (level > 1) {
        PrintNodeGivenLevel(root->left, level-1);
        PrintNodeGivenLevel(root->right, level-1);
    }
}

/*
 *Level order traversal using height of the tree
 */
void LevelOrderTraverseUsingHeightRecursive(Node* root) {
    int height = HeightRecursive(root);
    for (int i=1; i<=height; i++) {
        PrintNodeGivenLevel(root, i);
    }
}

/*
 *Level order traversal using queue
 */
void LevelOrderTraverseUsingQueueRecursive(Node* root) {
    std::queue<Node*> loqueue; //Level order queue
    loqueue.push(root);

    while (!loqueue.empty()) {
        Node* node = loqueue.front();
        loqueue.pop();
        std::cout <<node->data <<" ";

        /* Enqueue the left child */
        if (node->left) {
            loqueue.push(node->left);
        }

        /* Enqueue the right child */
        if (node->right) {
            loqueue.push(node->right);
        }
    }
}
