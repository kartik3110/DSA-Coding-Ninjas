#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class node
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

void zigZagOrder(node<int> *root)
{
    stack<node<int> *> st2;
    stack<node<int> *> st1;
    if (!root)
    {
        return;
    }
    st1.push(root);
    while (!st2.empty() && !st1.empty())
    {
        while (!st1.empty())
        {
            node<int> *frontNode = st1.top();
            st1.pop();
            cout << frontNode->data << " ";
            if (frontNode->left)
                st2.push(frontNode->left);
            if (frontNode->right)
                st2.push(frontNode->right);
        }
        cout << endl;
        while (!st2.empty())
        {
            node<int> *topNode = st2.top();
            st2.pop();
            cout << topNode->data << " ";
            if (topNode->right)
                st1.push(topNode->right);
            if (topNode->left)
                st1.push(topNode->left);
        }
        cout << endl;
    }
}