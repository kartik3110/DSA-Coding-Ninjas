#include <iostream>
#include <vector>
#include <algorithm>
#include "binaryTreeNode.cpp"
using namespace std;
vector<int> ans;
void treeToArray(node<int> *root)
{

    if (!root)
    {
        return;
    }
    ans.push_back(root->data);
    treeToArray(root->left);
    treeToArray(root->right);
}
void pairSum(node<int> *root, int sum)
{
    // approach 1. convert tree to array and then solve it like the two-sum problem by using 2 pointers
    // approach 2. traverse whole tree for every element (O(N^2))
    treeToArray(root);
    sort(ans.begin(), ans.end());
    int l = 0;
    int r = ans.size() - 1;
    while (l < r)
    {
        if (ans[l] + ans[r] == sum)
        {
            cout << ans[l++] << ans[r--] << endl;
        }
        else if (ans[l] + ans[r] < sum)
        {
            l++;
        }
        else if (ans[l] + ans[r] > sum)
        {
            r--;
        }
    }
}
