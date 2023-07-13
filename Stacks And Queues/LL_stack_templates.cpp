#include <iostream>
#include <climits>
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node<T> *next; // points to next node

public:
    node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class stack
{
    node<T> *head;
    int totalSize;

public:
    stack()
    {
        head = NULL;
        totalSize = 0
    }

    int getSize()
    {
        return totalSize;
    }

    bool isEmpty()
    {
        return totalSize == 0;
    }

    void push(T data)
    {
        node<T> *newNode = new node(data);
        newNode->next = head;
        head = newNode;
        totalSize++;
    }

    T pop()
    {
        if (totalSize == 0)
        {
            return -1;
        }
        int ans = head->data;
        node<T> *temp = head;
        head = head->next;
        delete temp;
        totalSize--;
        return ans;
    }

    T top()
    {
        if (totalSize == 0)
        {
            return -1;
        }
        return head->data;
    }
};
