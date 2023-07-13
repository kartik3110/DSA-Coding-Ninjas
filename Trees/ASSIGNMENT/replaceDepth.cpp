#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;
void replace(TreeNode<int> *root, int x)
{
    if (!root)
        return;
    root->data = x;
    for (int i = 0; i < root->children.size(); i++)
    {
        replace(root->children[i], x + 1);
    }
}
void replaceWithDepthValue(TreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    replace(root, 0);
}
