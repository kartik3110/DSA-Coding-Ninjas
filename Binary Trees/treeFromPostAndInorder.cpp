#include <iostream>
#include <queue>
#include "binaryTreeNode.cpp"
using namespace std;

node<int> *builder(int *preOrder, int *inOrder, int preStart, int preEnd, int inStart, int inEnd)
{
    if (inStart > inEnd) // can use prestart aswell
    {
        return;
    }
    int rootData = preOrder[preStart];
    int rootIndexInOrder;
    for (int i = inStart; i < inEnd; i++)
    {
        if (inOrder[i] == rootData)
        {
            rootIndexInOrder = i;
            break;
        }
    }

    int leftInS = inStart;                       // left inOrder start
    int leftInE = rootIndexInOrder - 1;          // left inOrder end
    int leftPreS = preStart + 1;                 // left preOrder start
    int leftPreE = leftInE - leftInS + leftPreS; // left preOrder end

    int rightPreS = leftPreE + 1;        // right preOrder start
    int rightPreE = preEnd;              // right preOrder end
    int rightInS = rootIndexInOrder + 1; // right inOrder start
    int rightInE = inEnd;                // right inOrder end
    node<int> *root = new node<int>(rootData);
    root->left = builder(preOrder, inOrder, leftPreS, leftPreE, leftInS, leftInE);
    root->right = builder(preOrder, inOrder, rightPreS, rightPreE, rightInS, rightInE);
    return root;
}

node<int> *buildTree(int *preOrder, int preLength, int *inOrder, int inLength)
{
    return builder(preOrder, inOrder, 0, preLength - 1, 0, inLength - 1);
}
