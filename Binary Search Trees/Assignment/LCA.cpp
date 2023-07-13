#include <iostream>
#include <vector>
#include <algorithm>
#include "binaryTreeNode.cpp"
using namespace std;
// return data of LCA
int getLCA(node<int> *root, int a, int b)
{
    if (!root)
    {
        return -1;
    }
    if (root->data == a || root->data == b)
    {
        return root->data;
    }
    int leftLCA = getLCA(root->left, a, b);
    int rightLCA = getLCA(root->right, a, b);

    if (leftLCA != -1 && rightLCA == -1)
    {
        return leftLCA;
    }
    else if (leftLCA == -1 && rightLCA != -1)
    {
        return rightLCA;
    }
    else if (leftLCA == -1 && rightLCA == -1)
    {
        return -1;
    }
    else if (leftLCA != -1 && rightLCA != -1)
    {
        return root->data;
    }
}