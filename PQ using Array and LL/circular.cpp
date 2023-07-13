#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = this;
    }
};

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *insertTail(node *head, int data)
{
    node *newNode = new node(data);
    node *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->next = head;
    return head;
}
int main()
{
    node *n1 = new node(10);
    // node n2(20);
    // n1.next = &n2;
    int k = 8;
    node *head = n1;
    head = insertTail(head, 20);
    head = insertTail(head, 233);
    head = insertTail(head, 23);
    while (k)
    {
        cout << head->data << endl;
        head = head->next;
        k--;
    }

    return 0;
}