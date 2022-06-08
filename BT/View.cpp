#include <queue> 
#include <map> 
#include <unordered_map> 
#include "BT.hpp" 

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

/*
 *Print the left node for each level
 */
static void PrintLeftView(Node* node, int level, int& maxlevel) {
    if (!node) {
        return;
    }

    if (level > maxlevel) {
        std::cout <<node->data <<" ";
        maxlevel = level; //To skip the other node on the level
    }
    PrintLeftView(node->left, level+1, maxlevel);
    PrintLeftView(node->right, level+1, maxlevel);
}

/*
 *Print the left view of the tree
 *We will use a variable to track the level and p
 */
void LeftViewOfTreeUsingLevelVariableRecursive(Node* root) {
    int maxlevel = 0;
    PrintLeftView(root, 1, maxlevel);
}

/*
 *Print the right node for each level
 */
static void PrintRightView(Node* node, int level, int& maxlevel) {
    if (!node) {
        return;
    }

    if (level > maxlevel) {
        std::cout <<node->data <<" ";
        maxlevel = level; //To skip the other node on the level
    }
    PrintRightView(node->right, level+1, maxlevel);
    PrintRightView(node->left, level+1, maxlevel);
}

void RightViewOfTreeUsingLevelVariableRecursive(Node* root) {
    int maxlevel = 0;
    PrintRightView(root, 1, maxlevel);
}


/*
 *HD -> Horizontal Distance
 *This approach does not require a queue. Here we use the two variables, one for vertical distance of current node from the root and another for the depth of the current node from the root. We use the vertical distance for indexing. If one node with the same vertical distance comes again, we check if depth of new node is lower or higher with respect to the current node with same vertical distance in the map. If depth of new node is lower, then we replace it.
 */
// function to fill the map
static void fillMap(Node* root, int hd, int level, std::map<int, std::pair<int, int>>& m)
{
    if (root == NULL)
        return;

    if (m.count(hd) == 0) {
        m[hd] = std::make_pair(root->data, level);
    }
    else if (m[hd].second > level) {
        m[hd] = std::make_pair(root->data, level);
    }

    fillMap(root->left, hd - 1, level + 1, m);
    fillMap(root->right, hd + 1, level + 1, m);
}

// function should print the topView of
// the binary tree
void topView(struct Node* root)
{
    // map to store the pair of node value and its level
    // with respect to the vertical distance from root.
    std::map<int, std::pair<int, int>> m;

    // fillmap(root,hd,level,map)
    fillMap(root, 0, 0, m);

    for (auto it : m) {
        std::cout << it.second.first << " ";
    }
}

#if 0
/*
 * This approach is based on the level order traversal. We’ll keep record of current max so far left, right horizontal distances from the root.
 And if we found less distance (or greater in magnitude) then max left so far distance then update it and also push data on this node to a stack (stack is used because in level order traversal the left nodes will appear in reverse order), or if we found greater distance then max right so far distance then update it and also push data on this node to a vector.
 In this approach, no map is used.
 */ 

void topView()
{
    // queue for holding nodes and their horizontal
    // distance from the root node
    queue<std::pair<Node*, int> > q;

    // pushing root node with distance 0
    q.push(std::make_pair(root, 0));

    // hd is current node's horizontal distance from
    // root node l is current left min horizontal
    // distance (or max in magnitude) so far from the
    // root node r is current right max horizontal
    // distance so far from the root node

    int hd = 0, l = 0, r = 0;

    // stack is for holding left node's data because
    // they will appear in reverse order that is why
    // using stack
    stack<int> left;

    // vector is for holding right node's data
    vector<int> right;

    Node* node;

    while (q.size()) {

        node = q.front().first;
        hd = q.front().second;

        if (hd < l) {
            left.push(node->data);
            l = hd;
        }
        else if (hd > r) {
            right.push_back(node->data);
            r = hd;
        }

        if (node->left) {
            q.push(std::make_pair(node->left, hd - 1));
        }
        if (node->right) {
            q.push(std::make_pair(node->right, hd + 1));
        }

        q.pop();
    }
    // printing the left node's data in reverse order
    while (left.size()) {
        std::cout << left.top() << " ";
        left.pop();
    }

    // then printing the root node's data
    std::cout << root->data << " ";

    // finally printing the right node's data
    for (auto x : right) {
        std::cout << x << " ";
    }
}
#endif
