#include <iostream>
#include <bits/stdc++.h>
#include "binaryTreeNode.cpp"
using namespace std;

map<node<int> *, node<int> *> parent;

void mapChildToParent(node<int> *root)
{
    if (!root)
    {
        return;
    }
    if (root->left)
    {
        parent[root->left] = root;
    }
    if (root->right)
    {
        parent[root->right] = root;
    }
    mapChildToParent(root->left);
    mapChildToParent(root->right);
}

node<int> *findNode(node<int> *root, int target)
{
    if (!root)
        return NULL;

    if (root->data == target)
        return root;

    node<int> *leftAns = findNode(root->left, target);
    node<int> *rightAns = findNode(root->right, target);
    if (leftAns)
        return leftAns;
    else
        return rightAns;
}

void nodesAtDistanceK(node<int> *root, int target, int distance)
{
    if (!root)
        return;
    mapChildToParent(root);
    node<int> *targetNode = findNode(root, target);
    queue<node<int> *> q;
    map<node<int> *, bool> visitedNodes;
    q.push(targetNode);
    visitedNodes[targetNode] = true;
    while (!q.empty())
    {
        int currentSize = q.size();
        if (distance-- == 0)
            break;
        for (int i = 0; i < currentSize; i++)
        {
            node<int> *frontNode = q.front();
            q.pop();

            if (parent[frontNode] && !visitedNodes[parent[frontNode]]) // parent is found
            {
                q.push(parent[frontNode]);
                visitedNodes[parent[frontNode]] = true;
            }
            if (frontNode->left && !visitedNodes[frontNode->left])
            {
                q.push(frontNode->left);
                visitedNodes[frontNode->left] = true;
            }
            if (frontNode->right && !visitedNodes[frontNode->right])
            {
                q.push(frontNode->right);
                visitedNodes[frontNode->right] = true;
            }
        }
    }
    while (!q.empty())
    {
        cout << q.front()->data << endl;
        q.pop();
    }
}
