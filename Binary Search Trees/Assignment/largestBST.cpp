#include <iostream>
#include <vector>
#include <climits>
#include "binaryTreeNode.cpp"
using namespace std;

class info
{
public:
    bool isBst;
    int min;
    int max;
    int height;
};

info largestSubtreeHelper(node<int> *root)
{
    if (!root)
    {
        info ans;
        ans.isBst = true;
        ans.height = 0;
        ans.max = INT_MIN;
        ans.min = INT_MAX;
        return ans;
    }
    info ans;
    info leftAns = largestSubtreeHelper(root->left);
    info rightAns = largestSubtreeHelper(root->right);

    ans.max = max(root->data, max(leftAns.max, rightAns.max));
    ans.min = min(root->data, min(leftAns.min, rightAns.min));
    ans.height = max(leftAns.height, rightAns.height);
    ans.isBst = false;

    if (root->data > leftAns.max && root->data <= rightAns.min && leftAns.isBst && rightAns.isBst)
    {
        ans.isBst = true;
        ans.height = 1 + max(leftAns.height, rightAns.height); // height only increments when a bst is found
    }
    return ans;
}

int largestBSTSubtree(node<int> *root)
{
    return largestSubtreeHelper(root).height;
}