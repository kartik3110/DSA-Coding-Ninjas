#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;

int getHeight(TreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    vector<int> smallAns;
    for (int i = 0; i < root->children.size(); i++)
    {
        smallAns.push_back(getHeight(root->children[i]));
    }
    int max;
    for (int i = 0; i < smallAns.size(); i++)
    {
        if (max < smallAns[i])
        {
            max = smallAns[i];
        }
    }
    return max + 1;
}
int main()
{

    return 0;
}