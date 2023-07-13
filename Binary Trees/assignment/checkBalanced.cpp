#include <iostream>
#include <climits>
#include "binaryTreeNode.cpp"
using namespace std;

int height(node<int> *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(node<int> *root)
{
    if (!root)
    {
        return true;
    }
    /*lh = 3, rh = 4, absof diff < 1 , true.*/
    bool isLeftBalanced = isBalanced(root->left);
    bool isRightBalanced = isBalanced(root->right);

    if (abs(height(root->left) - height(root->right)) <= 1 && isLeftBalanced && isRightBalanced)
    {
        return true;
    }
    return false;
}