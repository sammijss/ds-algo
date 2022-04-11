#include "BT.hpp"

/*
 *        50
 *     /      \
 *    30       70
 *   /  \     /  \ 
 *  20   40  60   80
 */

int main()
{
    Node* root = NULL;
    root = AddNode(root, 50);
    AddNode(root, 30);
    AddNode(root, 20);
    AddNode(root, 40);
    AddNode(root, 70);
    AddNode(root, 60);
    AddNode(root, 80);

    std::cout <<"Height: " <<HeightRecursive(root) <<std::endl; 

    std::cout <<"Preorder:\t";
    PreorderTraverseRecursive(root);
    std::cout <<std::endl;

    std::cout <<"Inorder:\t";
    InorderTraverseRecursive(root);
    std::cout <<std::endl;

    std::cout <<"Postorder:\t";
    PostorderTraverseRecursive(root);
    std::cout <<std::endl;

    std::cout <<"Levelorder:\t";
    LevelOrderTraverseUsingHeightRecursive(root);
    std::cout <<std::endl;

    std::cout <<"Levelorder:\t";
    LevelOrderTraverseUsingQueueRecursive(root);
    std::cout <<std::endl;

    std::cout <<"Leftview:\t";
    LeftViewOfTreeUsingHashMapRecursive(root);
    std::cout <<std::endl;

    std::cout <<"Rightview:\t";
    RightViewOfTreeUsingHashMapRecursive(root);
    std::cout <<std::endl;

    std::cout <<"Leftview:\t";
    LeftViewOfTreeUsingQueueRecursive(root);
    std::cout <<std::endl;

    std::cout <<"Rightview:\t";
    RightViewOfTreeUsingQueueRecursive(root);
    std::cout <<std::endl;
    return(0);
}
