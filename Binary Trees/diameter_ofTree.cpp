#include <iostream>
#include <queue>
#include "binaryTreeNode.cpp"
using namespace std;

pair<int, int> diameterAndHeight(node<int> *root)
{
    if (!root)
    {
        pair<int, int> p;
        p.first = 0;  // height
        p.second = 0; // diameter
        return p;
    }
    pair<int, int> leftAns = diameterAndHeight(root->left);
    pair<int, int> rightAns = diameterAndHeight(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    pair<int, int> ans;
    ans.first = 1 + max(lh, rh);
    ans.second = max(lh + rh, max(ld, rd));
    return ans;
}
