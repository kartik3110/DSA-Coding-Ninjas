#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;

int countLeafs(TreeNode<int> *root)
{
    int ans = 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countLeafs(root->children[i]);
    }
    return ans;
}

// prints all nodes at level 'd'
void depth(TreeNode<int> *root, int d)
{
    if (!root) // edge case
    {
        return;
    }
    if (d == 0) // base case
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        depth(root->children[i], d - 1);
    }
}

int main()
{
    return 0;
}