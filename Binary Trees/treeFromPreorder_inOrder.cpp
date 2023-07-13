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

    int leftInS = inStart;                       // left inorder start
    int leftInE = rootIndexInOrder - 1;          // left inorder end
    int leftPreS = preStart + 1;                 // left preorder start
    int leftPreE = leftInE - leftInS + leftPreS; // left preorder end

    int rightPreS = leftPreE + 1;        // right preorder start
    int rightPreE = preEnd;              // right preorder end
    int rightInS = rootIndexInOrder + 1; // right inorder start
    int rightInE = inEnd;                // right inorder end
    node<int> *root = new node<int>(rootData);
    root->left = builder(preOrder, inOrder, leftPreS, leftPreE, leftInS, leftInE);
    root->right = builder(preOrder, inOrder, rightPreS, rightPreE, rightInS, rightInE);
    return root;
}

node<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    return builder(preorder, inorder, 0, preLength - 1, 0, inLength - 1);
}
