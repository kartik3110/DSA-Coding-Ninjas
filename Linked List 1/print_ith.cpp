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

void printIthNode(node *head, int i) // first element means element at 0th index
{
    int index = 0;
    node *temp = head;
    while (index < i - 1)
    {
        temp = temp->next;
        index++;
    }
    cout << temp->data;
}
int main()
{
    node *head = takeInput();
    printIthNode(head, 3);
    return 0;
}