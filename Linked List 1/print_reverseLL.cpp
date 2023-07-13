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

void printReverse(node *head)
{
    if (head == NULL)
    {
        return;
    }
    printReverse(head->next);
    cout << head->data << " ";
}
int main()
{
    node *head = takeInput();
    printReverse(head);
    return 0;
}