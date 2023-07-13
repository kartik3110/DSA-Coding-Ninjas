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
        node *newnode = new node(data);
        if (head == NULL) // means its the first node
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}
// recursive(time limit exceeded)
node *evenAfterOdd(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *smallHead = evenAfterOdd(head->next);
    head->next = smallHead;  // append old head
    if (head->data % 2 != 0) // head is odd
    {
        return head;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL && temp->next->data % 2 != 0) // while temp ke next ka data is odd
        {
            temp = temp->next;
        }
        if (temp == head) // there were no odd numbers in the LL
        {
            return head;
        }
        node *temp2 = temp->next;
        temp->next = head;
        head->next = temp2;
        return smallHead;
    }
}

int main()
{
    node *head = takeInput();
    return 0;
}
