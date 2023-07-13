#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;

int sumOfNodes(TreeNode<int> *root)
{
    int ans = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumOfNodes(root->children[i]);
    }
    return ans;
}

int countNodes(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNodes(root->children[i]);
    }
    return ans;
}
int main()
{

    return 0;
}