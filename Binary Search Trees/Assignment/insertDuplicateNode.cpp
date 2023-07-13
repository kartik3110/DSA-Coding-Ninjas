#include <iostream>
#include "binaryTreeNode.cpp"
using namespace std;

void insertDuplicateNode(node<int> *root)
{
    if (!root)
    {
        return;
    }
    node<int> *newNode = new node<int>(root->data);
    if (!root->left)
    {
        root->left = newNode;
    }
    else
    {
        node<int> *temp = root->left;
        root->left = newNode;
        newNode->left = temp;
        insertDuplicateNode(temp);
    }
    insertDuplicateNode(root->right);
}