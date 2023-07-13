#include <iostream>
#include <queue>
#include "binaryTreeNode.cpp"
using namespace std;

node<int> *removeLeafNodes(node<int> *root)
{
    if (!root)
    {
        return NULL;
    }
    if (!root->left && !root->right) // means its a leaf
    {
        delete root;
        return NULL;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}
