#include <iostream>
#include <climits>
#include "binaryTreeNode.cpp"
using namespace std;
class Triplet
{
public:
    bool isBst;
    int maximum;
    int minimum;
};

Triplet isTreeBst(node<int> *root)
{
    Triplet ans;
    if (!root)
    {
        ans.isBst = true;
        ans.maximum = INT_MIN;
        ans.minimum = INT_MAX;
        return ans;
    }
    Triplet leftAns = isTreeBst(root->left);
    Triplet rightAns = isTreeBst(root->right);

    ans.maximum = max(root->data, max(leftAns.maximum, rightAns.maximum));
    ans.minimum = min(root->data, min(leftAns.minimum, rightAns.minimum));
    ans.isBst = leftAns.isBst && rightAns.isBst && (root->data > leftAns.maximum) && (root->data <= rightAns.minimum);

    return ans;
}

bool isBST(node<int> *root)
{
    return isTreeBst(root).isBst;
}