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
node *skipMdeleteN(node *head, int m, int n)
{
    // corner cases
    if (head == NULL || n == 0)
    {
        return head;
    }
    if (m == 0)
    {
        return NULL;
    }
    node *temp1 = head;
    node *temp2 = head;
    while (temp1 != NULL && temp2 != NULL)
    {
        int count1 = 1;
        int count2 = 1;
        while (count1 < m && temp1->next != NULL)
        {
            temp1 = temp1->next;
            count1++;
        }
        temp2 = temp1->next;
        node *waste = temp2;
        while (count2 <= n && temp2 != NULL)
        {
            temp2 = temp2->next;
            delete waste;
            waste = temp2;
            count2++;
        }
        temp1->next = temp2;
        temp1 = temp2;
    }
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
    head = skipMdeleteN(head, 2, 3);
    print(head);
    return 0;
}