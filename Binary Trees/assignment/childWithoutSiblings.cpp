#include <iostream>
#include <queue>
#include "binaryTreeNode.cpp"
using namespace std;

void printNodesWithoutSibling(node<int> *root)
{
    if (!root)
    {
        return;
    }
    if (root->left && !root->right)
    {
        cout << root->left << " ";
    }
    else if (root->right && !root->left)
    {
        cout << root->right << " ";
    }
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}
