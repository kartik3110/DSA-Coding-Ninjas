#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    if (!root)
    {
        return NULL;
    }
    TreeNode<int> *ans = NULL;
    if (root->data > x)
    {
        ans = root;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *smallAns = getNextLargerElement(root->children[i], x);
        if (smallAns && ans && smallAns->data < ans->data || (smallAns && !ans))
        {
            ans = smallAns;
        }
    }
    return ans;
}