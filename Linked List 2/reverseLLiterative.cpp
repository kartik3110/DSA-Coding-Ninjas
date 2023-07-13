#include <iostream>
#include "nodeClass.cpp"
using namespace std;
node *takeInput()
{
    cout << "enter datas(-1 to exit): " << endl;
    int data;
    node *head = NULL;
    node *tail = NULL;
    cin >> data;
    while (data != -1)
    {
        node *newNode = new node(data);
        if (head == NULL) // means its the first node
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

node *iterativeReverse(node *head)
{
    node *current = head;
    node *prev = NULL;
    node *n = head->next;
    while (current != NULL || current->next != NULL)
    {
        current->next = prev;
        prev = current;
        current = n;
        n = n->next;
    }
    return current;
}
int main()
{
    node *head = takeInput();
    iterativeReverse(head);
    return 0;
}