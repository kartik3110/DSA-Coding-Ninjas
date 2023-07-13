#include <iostream>
#include "binaryTreeNode.cpp"
using namespace std;

bool searchInBST(node<int> *root, int k)
{
    if (!root)
    {
        return NULL;
    }
    if (root->data == k)
    {
        return true;
    }
    if (root->data > k)
    {
        return searchInBST(root->left, k);
    }
    if (root->data < k)
    {
        return searchInBST(root->right, k);
    }
}