#include <iostream>
#include <climits>
#include <vector>
#include "binaryTreeNode.cpp"
using namespace std;
template <typename T>
class llNode // linked list
{
public:
    T data;
    llNode<T> *next;

    llNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class llPair
{
public:
    llNode<int> *head;
    llNode<int> *tail;
};

llPair makeLinkedList(node<int> *root)
{
    // get left and right linked lists and attach the root in between
    if (root == NULL)
    {
        llPair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }

    llNode<int> *newNode = new llNode<int>(root->data);

    llPair leftans = makeLinkedList(root->left);
    llPair rightans = makeLinkedList(root->right);

    llPair ans;

    if (!leftans.head && !rightans.head)
    {

        ans.head = newNode;
        ans.tail = newNode;
    }

    else if (!leftans.head && rightans.head)
    {
        ans.head = newNode;
        newNode->next = rightans.head;

        ans.tail = rightans.tail;
    }
    else if (leftans.head && !rightans.head)
    {
        ans.head = leftans.head;
        leftans.tail->next = newNode;
        ans.tail = newNode;
    }

    else
    {
        ans.head = leftans.head;
        leftans.tail->next = newNode;
        newNode->next = rightans.head;
        ans.tail = rightans.tail;
    }
    return ans;
}

llNode<int> *constructLinkedList(node<int> *root)
{
    return makeLinkedList(root).head;
}