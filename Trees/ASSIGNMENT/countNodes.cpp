#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;

int getLargeNodeCount(TreeNode<int> *root, int x)
{
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += getLargeNodeCount(root->children[i], x);
    }
    if (root->data > x)
    {
        ans++;
    }
    return ans;
}

int main()
{
    return 0;
}