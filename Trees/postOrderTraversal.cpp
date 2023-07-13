#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;

void printPostOrder(TreeNode<int> *root)
{
    if (!root->children.size())
    {
        cout << root << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printPostOrder(root->children[i]);
    }
}

int main()
{
    return 0;
}