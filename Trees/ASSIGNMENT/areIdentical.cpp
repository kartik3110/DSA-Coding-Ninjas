#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;

bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (!root1 && !root2)
    {
        return false;
    }
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }
    bool ans = false;
    if (root1->data == root2->data)
    {
        ans = true;
        for (int i = 0; i < root1->children.size(); i++)
        {
            if (!areIdentical(root1->children[i], root2->children[i]))
            {
                ans = false;
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}