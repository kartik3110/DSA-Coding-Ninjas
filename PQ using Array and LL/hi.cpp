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
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        cout << "FRee the memory of" << value << endl;
    }
};
void insertathead(int d, node *&head)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

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
void insertattail(int d, node *&tail)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void mid(int d, int p, node *&head, node *&tail)
{
    if (p == 1)
    {
        insertathead(d, head);
        return;
    }
    node *temp = head;
    for (int i = 1; i < p - 1; i++)
    {
        temp = temp->next;
    }
    node *nodeToBeInserted = new node(d);
    nodeToBeInserted->next = temp->next;
    temp->next = nodeToBeInserted;
    if (temp->next == NULL)
    {
        insertattail(d, tail);
        return;
    }
}
void deletion(int p, node *&head, node *&tail)
{
    if (p == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {

        node *previous = NULL;
        node *current = head;
        for (int i = 1; i < p; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        if (current->next == NULL)
        {
            tail = previous;
        }
        current->next = NULL;
        delete current;
    }
}

void reverse(node *&head)
{
    node *current = head;
    node *prev = NULL;
    node *forward = current->next;
    while (current != NULL && current->next != NULL)
    {
        current->next = prev;
        prev = current;
        current = forward;
        forward = forward->next;
    }
    current->next = prev;
    head = current;
}
int main()
{
    node *node1 = new node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    node *head = node1;
    node *tail = node1;
    insertathead(12, head);
    // print(head);
    insertattail(15, tail);
    print(head);
    // mid(2, 1, head, tail);
    // // print(head);
    // // deletion(4,head,tail);
    // print(head);
    // cout << endl;
    // cout<<"head"<<head->data<<endl;
    // cout<<"tail"<<tail->data;
    reverse(head);
    print(head);
}