#include <iostream>
#include <queue>
#include "binaryTreeNode.cpp"
using namespace std;

// push a NULL after each level
void printLevelWise(node<int> *root)
{
    if (!root)
    {
        return;
    }
    queue<node<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node<int> *frontNode = q.front();
        q.pop();
        if (frontNode == NULL) // means a level is done printing
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
    }
}
