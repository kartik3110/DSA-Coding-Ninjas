#include <iostream>
#include <climits>
#include "binaryTreeNode.cpp"
using namespace std;

int getSum(node<int> *root)
{
    // Write your code here
    if (!root)
    {
        return 0;
    }
    return root->data + getSum(root->left) + getSum(root->right);
}