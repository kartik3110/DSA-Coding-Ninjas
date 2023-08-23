#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    node *left;
    node *right;

    node(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~node()
    {
        delete left;
        delete right; // now we can call delete root
    }
};

int count_nodes(BinaryTreeNode<int> *root)
{
    int count = 1;
    count += count_nodes(root->left);
    count += count_nodes(root->right);
    return count;
}
void printNodesSumToS(BinaryTreeNode<int> *root, int sum)
{
    if (root == NULL)
    {
        return;
    }
    stack<BinaryTreeNode<int> *> s1; // to store inorder traversal
    stack<BinaryTreeNode<int> *> s2; // to store reverse inorder traversal
    int counter = count_nodes(root);
    int nodesVisited = 0;

    BinaryTreeNode<int> *node = root;
    while (node != NULL)
    {
        s1.push(node);
        node = node->left;
    }
    node = root;
    node = node->right; // we have already included root in inorder traversal  toh hm usko stack 2 mein include nai kr rhe .ilsiye hi hmne node push krne se phle node->right kr dia
    while (node != NULL)
    {
        s1.push(node);
        node = node->right;
    }
    while (nodesVisited < counter)
    {
        BinaryTreeNode<int> *x = s1.top();
        BinaryTreeNode<int> *y = s2.top();
        if (x->data + y->data == sum)
        {
            cout << x->data << " " << y->data;

            s1.pop();
            nodesVisited++;
            if (x->right != NULL)
            {
                s1.push(x->right);
                x = x->right;
                x = x->left;
                while (x != NULL)
                {
                    s1.push(x);
                    x = x->left;
                }
            }
            s2.pop();
            nodesVisited++;
            if (y->left != NULL)
            {
                s2.push(y->left);
                y = y->left;
                y = y->right;
                while (y != NULL)
                {
                    s2.push(y);
                    y = y->right;
                }
            }
        }
        else if (x->data + y->data > sum)
        {
            s2.pop();
            // push 2nd largest element
            nodesVisited++;
        }
        else if (x->data + y->data < sum)
        {
            s1.pop();
            // push second smallest element
            nodesVisited++;
        }
    }
}
