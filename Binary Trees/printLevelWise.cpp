#include <iostream>
#include <queue>
#include "binaryTreeNode.cpp"
#include "takeInput.cpp"
using namespace std;

void printLevelWise(node<int> *root)

{
    if (!root)
    {
        return;
    }
    queue<node<int> *> q;
    q.push(root);
    while (q.size())
    {
        node<int> *front = q.front();
        q.pop();
        cout << front->data << ":";
        if (front->left)
        {
            q.push(front->left);
            cout << "L" << front->left->data << " ";
        }
        if (front->right)
        {
            q.push(front->right);
            cout << "R" << front->right->data << " ";
        }
        cout << endl;
    }
}

int main()
{
    node<int> *root = takeInputLevelWise();
    printLevelWise(root);

    return 0;
}
