#include <iostream>
#include <climits>
#include <vector>
#include "binaryTreeNode.cpp"
using namespace std;

node<int> *constructTree(int *input, int n)
{
    if (!n)
        return NULL;
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    node<int> *root = new node<int>(input[mid]);
    root->left = constructTree(input, n - 1 - mid);
    root->right = constructTree(input + mid + 1, n);
    return root;
}
