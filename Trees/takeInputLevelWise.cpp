#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "enter root data: ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        int n;
        TreeNode<int> *parent = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter no. of children of " << parent->data << ": ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int childData;
            cout << "enter " << i << "th child's data: ";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            parent->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTree(TreeNode<int> *root)
{
    cout << root->data << ": ";

    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }

    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
int height(TreeNode<int> *root)
{
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int smallAns = height(root->children[i]);
        ans = max(ans, smallAns);
    }
    return ans + 1;
}
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
    TreeNode<int> *myTree = takeInputLevelWise();
    // printTree(myTree);
    cout << getHeight(myTree);
    return 0;
}