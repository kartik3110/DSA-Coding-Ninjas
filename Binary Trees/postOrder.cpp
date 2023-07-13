#include <iostream>
#include <queue>
#include "binaryTreeNode.cpp"
using namespace std;

node<int> *takeInputLevelWise()
{
    queue<node<int> *> q;
    int rootData;
    cout << "enter root data ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    node<int> *root = new node<int>(rootData);
    q.push(root);
    while (q.size())
    {
        node<int> *front = q.front();
        q.pop();
        cout << "enter left child of " << front->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            node<int> *left = new node<int>(leftData);
            front->left = left;
            q.push(left);
        }

        cout << "enter right child of " << front->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            node<int> *right = new node<int>(rightData);
            front->right = right;
            q.push(right);
        }
    }
    return root;
}
void postOrder(node<int> *root)
{
    if (!root)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    node<int> *root = takeInputLevelWise();
    postOrder(root);
    return 0;
}
