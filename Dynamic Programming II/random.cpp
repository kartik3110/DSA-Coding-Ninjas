#include <bits/stdc++.h>
using namespace std;

BinaryTreeNode<int> *buildTree(int *postorder, int postLength, int *inorder, int inLength)
{
    int rootData = postorder[postLength - 1];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    `

        if (postLength == 1) return root;

    else if (postLength == 0) return NULL;

    int rootIndex = 0;

    while (inorder[rootIndex] != rootData)
        rootIndex++;

    int leftLength = rootIndex;
    int rightLength = inLength - rootIndex - 1;
    root->left = buildTree(postorder, leftLength, inorder, leftLength);
    root->right = buildTree(postorder + leftLength, rightLength, inorder + rootIndex + 1, rightLength);
    return root;
}