#include <iostream>
#include "binaryTreeNode.cpp"
using namespace std;

void elementsInRangeK1K2(node<int> *root, int k1, int k2)
{
    // Write your code here
    if (root == NULL)
        return;
    if (k2 < root->data)
        elementsInRangeK1K2(root->left, k1, k2);
    else if (k1 > root->data)
        elementsInRangeK1K2(root->right, k1, k2);
    else if (k1 <= root->data && k2 >= root->data)
    {
        elementsInRangeK1K2(root->left, k1, k2);
        cout << root->data << " "; // root after left to print in increasing order
        elementsInRangeK1K2(root->right, k1, k2);
    }
}