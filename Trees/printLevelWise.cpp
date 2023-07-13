#include <iostream>
#include <queue>
#include "treeNode.cpp"
using namespace std;
void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        cout << pendingNodes.front() << ": ";
        pendingNodes.pop();
        for (int i = 0; i < pendingNodes.front()->children.size(); i++)
        {
            pendingNodes.push(pendingNodes.front()->children[i]);
            cout << pendingNodes.front()->children[i]->data << ",";
        }
    }
}

int countNodes(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNodes(root->children[i]);
    }
    return ans;
}
int main()
{

    return 0;
}