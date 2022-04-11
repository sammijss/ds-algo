#include <queue> 
#include <unordered_map> 
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

/*
 *Print add the only left node to the hashmap of given level
 */
static void AddLeftNodeToHashMap(Node* node, std::unordered_map<int, Node*>& hashmap, int level) {
    if (!node) {
        return;
    }

    //IT WILL PRINT FROM LAST TO FIRST LEVEL DATA
    //TO PRINT FIRST TO LAST LEVEL, MOVE THESE 3 LINES AT THE END OF THIS FUNCTION
    if (hashmap.find(level) == hashmap.end()) {
        hashmap.insert(std::make_pair(level, node));
    }

    AddLeftNodeToHashMap(node->left, hashmap, level+1);
    AddLeftNodeToHashMap(node->right, hashmap, level+1);
}

/*
 *Print the left view of the tree
 *Idea is to go to each level and add only left node, using level to node mapping.
 *Next time when we will visit the same level we will not add any node because we will already has a node.
 */
void LeftViewOfTreeUsingHashMapRecursive(Node* root) {
    std::unordered_map<int, Node*> hashmap;
    AddLeftNodeToHashMap(root, hashmap, 1);
    for (auto& it : hashmap) {
        std::cout <<it.second->data <<" ";
    }
}

/*
 *Print add the only right node to the hashmap of given level
 */
static void AddRightNodeToHashMap(Node* node, std::unordered_map<int, Node*>& hashmap, int level) {
    if (!node) {
        return;
    }

    //IT WILL PRINT FROM LAST TO FIRST LEVEL DATA
    //TO PRINT FIRST TO LAST LEVEL, MOVE THESE 3 LINES AT THE END OF THIS FUNCTION
    if (hashmap.find(level) == hashmap.end()) {
        hashmap.insert(std::make_pair(level, node));
    }

    AddRightNodeToHashMap(node->right, hashmap, level+1);
    AddRightNodeToHashMap(node->left, hashmap, level+1);
}

/*
 *Print the right view of the tree
 *Idea is to go to each level and add only right node, using level to node mapping.
 *Next time when we will visit the same level we will not add any node because we will already has a node.
 */
void RightViewOfTreeUsingHashMapRecursive(Node* root) {
    std::unordered_map<int, Node*> hashmap;
    AddRightNodeToHashMap(root, hashmap, 1);
    for (auto& it : hashmap) {
        std::cout <<it.second->data <<" ";
    }
}

/*
 *Print the left view of the tree
 *Idea is to do the level order traversal and print the only first node on each level
 */
void LeftViewOfTreeUsingQueueRecursive(Node* root) {
    std::queue<Node*> loqueue; //Level order queue
    loqueue.push(root);

    while(!loqueue.empty()) {
        int size = loqueue.size();
        for (int i=1; i<=size; i++) {
            Node* node = loqueue.front();
            loqueue.pop();

            if (i == 1) {
                std::cout <<node->data <<" ";
            }

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
}

/*
 *Print the right view of the tree
 *Idea is to do the level order traversal and print the only first node on each level
 */
void RightViewOfTreeUsingQueueRecursive(Node* root) {
    std::queue<Node*> loqueue; //Level order queue
    loqueue.push(root);

    while(!loqueue.empty()) {
        int size = loqueue.size();
        for (int i=1; i<=size; i++) {
            Node* node = loqueue.front();
            loqueue.pop();

            if (i == 1) {
                std::cout <<node->data <<" ";
            }

            /* Enqueue the right child */
            if (node->right) {
                loqueue.push(node->right);
            }

            /* Enqueue the left child */
            if (node->left) {
                loqueue.push(node->left);
            }
        }
    }
}
