#include <iostream>
#include <climits>
#include <vector>
#include "binaryTreeNode.cpp"
using namespace std;

vector<int> *getPath(node<int> *root, int k)
{
    vector<int> *ans = new vector<int>;
    if (!root)
    {
        return ans;
    }
    if (root->data == k)
    {
        ans->push_back(root->data);
        return ans;
    }
    if (root->data > k)
    {
        vector<int> *ansFromLeft = getPath(root->left, k);
        if (ansFromLeft->size())
        {
            ansFromLeft->push_back(root->data);
        }
        return ansFromLeft;
    }
    if (root->data < k)
    {
        vector<int> *ansFromRight = getPath(root->right, k);
        if (ansFromRight->size())
        {
            ansFromRight->push_back(root->data);
        }
        return ansFromRight;
    }
}