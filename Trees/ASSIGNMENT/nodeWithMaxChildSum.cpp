#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;

void maxSum(TreeNode<int> *root, TreeNode<int> **maxNode, int *maxSoFar)
{
    if (!root)
    {
        return;
    }
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    if (sum >= *maxSoFar)
    {
        *maxSoFar = sum;
        *maxNode = root;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        maxSum(root->children[i], maxNode, maxSoFar);
    }
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    TreeNode<int> *maxNode;
    int maxSoFar = 0;
    maxSum(root, &maxNode, &maxSoFar);
    return maxNode;
}
