#include <iostream>
#include <climits>
using namespace std;
class node
{
public:
    int data;
    node *next; // points to next node

public:
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class stack
{
    node *head;
    int totalSize = 0;

public:
    stack()
    {
        head = NULL;
    }

    int getSize()
    {
        return totalSize;
    }
    
    bool isEmpty()
    {
        return totalSize == 0;
    }

    void push(int data)
    {
        node *newNode = new node(data);
        newNode->next = head;
        head = newNode;
        totalSize++;
    }

    int pop()
    {
        if (totalSize == 0)
        {
            return -1;
        }
        node* temp = head;
		int ans = temp->data;
		head = head->next;
		delete temp;
		totalSize --;
		return ans;
    }

    int top()
    {
        if (totalSize == 0)
        {
            return -1;
        }
        return head->data;
    }
};

int main()

{
	cout<<"running stack using LL class";
}
