#include <iostream>
#include <climits>
#include <vector>
#include "binaryTreeNode.cpp"
using namespace std;

class BST
{
    node<int> *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    bool searchHelper(node<int> *rootNode, int k)
    {
        if (!rootNode)
        {
            return false;
        }
        if (rootNode->data == k)
        {
            return true;
        }
        if (rootNode->data > k)
        {
            return searchHelper(rootNode->left, k);
        }
        return searchHelper(rootNode->right, k);
    }

    node<int> *insertHelper(node<int> *rootNode, int k)
    {
        if (!rootNode)
        {
            node<int> *newNode = new node<int>(k);
            return newNode;
        }
        if (k <= rootNode->data)
        {
            rootNode->left = insertHelper(rootNode->left, k);
        }
        if (k > rootNode->data)

        {
            rootNode->right = insertHelper(rootNode->right, k);
        }

        return rootNode;
    }
    node<int> *findMin(node<int> *rootNode)
    {
        if (rootNode->left == NULL)
            return rootNode;
        return findMin(rootNode->left);
    }
    node<int> *removeHelper(node<int> *rootNode, int k)
    {
        if (!rootNode)
        {
            return NULL;
        }
        if (k > rootNode->data)
        {
            rootNode->right = removeHelper(rootNode->right, k);
        }
        if (k < rootNode->data)
        {
            return removeHelper(rootNode->left, k);
        }
        if (k == rootNode->data)
        {
            if (!rootNode->left && !rootNode->right)
            {
                delete rootNode;
                return NULL;
            }
            if (!rootNode->left)
            {
                node<int> *temp = rootNode->right;
                rootNode->right = NULL;
                delete rootNode;
                return temp;
            }
            if (!rootNode->right)
            {
                node<int> *temp = rootNode->left;
                rootNode->left = NULL;
                delete rootNode;
                return temp;
            }
            // reached here means rootnode has both children
            // replace the node with a leaf(either largest from left || smolest from right)
            node<int> *minNodeFromRight = findMin(rootNode->right);
            rootNode->data = minNodeFromRight->data;
            rootNode->right = removeHelper(rootNode->right, rootNode->data); // delete the leaf
            return rootNode;
        }
    }

    void printHelper(node<int> *rootNode)
    {
        if (!rootNode)
        {
            return;
        }
        cout << rootNode->data << ":";
        if (rootNode->left)
        {
            cout << "L:" << rootNode->left->data << ",";
        }
        if (rootNode->right)
        {
            cout << "R:" << rootNode->right->data;
        }
        cout << endl;
        printHelper(rootNode->left);
        printHelper(rootNode->right);
    }

public:
    bool search(int k) // O(H)
    {
        return searchHelper(root, k);
    }

    void insert(int k) // O(H)
    {
        this->root = insertHelper(root, k);
    }

    void remove(int k) // O(2H) = O(H)
    {
        this->root = removeHelper(root, k);
    }

    void print()
    {
        printHelper(root);
    }
};