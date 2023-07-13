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
int findNodeRec(node *head, int x)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == x)
    {
        return 0;
    }
    int smallAns = findNodeRec(head->next, x);
    if (smallAns == -1)
    {
        return -1;
    }
    else
        return smallAns + 1;
}

int main()
{
    node *head = takeInput();
    cout << findNodeRec(head, 24);
    return 0;
}