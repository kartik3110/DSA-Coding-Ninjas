#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;

bool isPresent(TreeNode<int> *root, int x)
{
    if (root->data == x)
    {
        return true;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        bool ans = isPresent(root->children[i], x);

        if (ans)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}