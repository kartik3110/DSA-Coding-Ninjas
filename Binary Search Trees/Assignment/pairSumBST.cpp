#include <iostream>
#include <bits/stdc++.h>
#include "binaryTreeNode.cpp"
using namespace std;
// Pair Sum in BST using O(H) space

//      5
//  3       7
// 2   4   6    9
//---------------
// space O(log n)

stack<node<int> *> st1; // left Subtree
stack<node<int> *> st2; // right Subtree
int totalNodes(node<int> *root)
{
    if (!root)
        return 0;

    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

void findMinAndPush(node<int> *root)
{
    if (!root)
        return;
    node<int> *temp = root;
    st1.push(temp);
    while (temp->left)
    {
        temp = temp->left;
        st1.push(temp);
    }
}
void findMaxAndPush(node<int> *root)
{
    if (!root)
        return;
    node<int> *temp = root;
    st2.push(temp);
    while (temp->right)
    {
        temp = temp->right;
        st2.push(temp);
    }
}
void printNodesSumToS(node<int> *root, int k)
{
    if (!root)
        return;

    int countOfVisitedNodes = totalNodes(root);
    countOfVisitedNodes--;
    findMinAndPush(root); // initialise st1
    findMaxAndPush(root); // initialise st2

    while (countOfVisitedNodes > 0)
    {
        node<int> *leftNode = st1.top();
        node<int> *rightNode = st2.top();
        if (leftNode->data + rightNode->data == k)
        {
            cout << leftNode->data << " " << rightNode->data << endl;
            st1.pop();
            st2.pop();
            findMinAndPush(leftNode->right);
            findMaxAndPush(rightNode->left);
            countOfVisitedNodes -= 2;
        }
        else if (leftNode->data + rightNode->data > k)
        {
            st2.pop();
            findMaxAndPush(rightNode->left);
            countOfVisitedNodes--;
        }
        else if (leftNode->data + rightNode->data < k)
        {
            st1.pop();
            findMinAndPush(leftNode->right);
            countOfVisitedNodes--;
        }
    }
}
