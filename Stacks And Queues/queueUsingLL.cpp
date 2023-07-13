#include <iostream>
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

class queue
{
    node *head;
    int size;
    node *tail;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int dequeue()
    {
    	node* temp = head;
    	head = head->next;
    	int ans = temp->data;
    	delete temp;
    	size--;
    	return ans;
	}
    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    int front()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }

    void enqueue(int element)
    {
        node *newNode = new node(element);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    int dequeue()
    {
        if (head == NULL)	//empty
        {
            return -1;
        }
        int ans = head->data;
        node *temp = head;
        if (head == tail)	//only one node was there so need to update the tail as well.
        {
            tail = NULL;
        }
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};
