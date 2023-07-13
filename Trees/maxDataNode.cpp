#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (!root)
    {
        return nullptr;
    }
    TreeNode<int> *max = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        if (max < maxDataNode(root->children[i]))
        {
            max = maxDataNode(root->children[i]);
        }
    }
    return max;
}
int main()
{

    return 0;
}