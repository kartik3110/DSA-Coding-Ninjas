#include <iostream>
#include <vector>
#include <climits>
#include "binaryTreeNode.cpp"
using namespace std;

int replace(node<int> *root, int sum)
{
    if (!root)
    {
        return 0;
    }
    // sum of all nodes is sum
    sum += replace(root->right, sum); // 15
    root->data += sum;
    sum = root->data;
    sum += replace(root->left, sum);
    return sum;
}

void replaceWithLargerNodesSum(node<int> *root)
{
    int x = replace(root, 0);
}