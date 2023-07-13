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

bool isTreeBst(node<int> *root, int maximum, int minimum)
{
    if (!root)
        return true;

    if (root->data < minimum || root->data >= maximum)
        return false;

    bool isLeftBst = isTreeBst(root->left, root->data, minimum);
    bool isRightBst = isTreeBst(root->right, maximum, root->data);
    return isLeftBst && isRightBst;
}

bool isBST(node<int> *root)
{
    return isTreeBst(root, INT_MAX, INT_MIN);
}