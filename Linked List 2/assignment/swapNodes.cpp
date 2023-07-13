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
node *swapNodes(node *head, int i, int j)
{
    node *temp1 = head;
    node *temp2 = head;
    while (i > 1)
    {
        temp1 = temp1->next;
        i--;
    }
    while (j > 0)
    {
        temp2 = temp2->next;
        j--;
    }
    node *temp3 = temp1->next;
    node *temp4 = temp2->next;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    return head;
}
void print(node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    print(head->next);
}

int main()
{
    node *head = takeInput();
    head = swapNodes(head, 2, 3);
    print(head);
    return 0;
}