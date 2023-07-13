#include <iostream>
#include <climits>
#include "binaryTreeNode.cpp"
using namespace std;

pair<int, int> getMinAndMax(node<int> *root)
{
    if (!root)
    {
        pair<int, int> p;
        p.second = INT_MIN; // max
        p.first = INT_MAX;  // min
        return p;
    }

    pair<int, int> leftAns = getMinAndMax(root->left);
    pair<int, int> rightAns = getMinAndMax(root->right);

    int lmax = leftAns.second;
    int lmin = leftAns.first;
    int rmax = rightAns.second;
    int rmin = rightAns.first;

    pair<int, int> ans;
    ans.second = max(root->data, max(lmax, rmax));
    ans.first = min(root->data, min(lmin, rmin));
    return ans;
}