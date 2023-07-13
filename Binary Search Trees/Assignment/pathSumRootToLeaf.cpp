#include <iostream>
#include <vector>
#include <algorithm>
#include "binaryTreeNode.cpp"
using namespace std;

void helperFunction(node<int> *root, int k, vector<int> path)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        if (k == root->data)
        {
            path.push_back(root->data);
            for (int i = 0; i < path.size(); i++)
            {
                cout << path[i] << " ";
            }
            return;
        }
        else
        {
            path.clear();
        }
    }
    k -= root->data;
    path.push_back(root->data);
    helperFunction(root->left, k, path);
    helperFunction(root->right, k, path);
}

void rootToLeafPathsSumToK(node<int> *root, int k)
{
    vector<int> v;
    helperFunction(root, k, v);
}
