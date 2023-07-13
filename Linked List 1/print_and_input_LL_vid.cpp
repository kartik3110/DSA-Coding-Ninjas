#include <iostream>
using namespace std;
#include "nodeClass.cpp"
void print(node *head)
{
    while (head != NULL) // works as this function makes its own copy of head.
    {
        cout << head->data << " ";
        head = head->next;
    }
}
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
int main()
{
    node *head = takeInput();
    print(head);
    return 0;
}