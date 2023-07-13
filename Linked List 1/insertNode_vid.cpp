#include <iostream>
#include "nodeClass.cpp"
using namespace std;

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
node *insertRecursive(node *head, int i, int data)
{
    if (head == NULL)
    {
        return head;
    }
    if (i == 0)
    {
        node *newNode = new node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    node *newHead = insertRecursive(head->next, i - 1, data);
    head->next = newHead;
    return head;
}
node *deleteRecursive(node *head, int i)
{
    if (head == NULL)
    {
        return head;
    }
    if (i == 0)
    {
        delete head;
        head = head->next;
        return head;
    }
    node *newHead = deleteRecursive(head->next, i - 1);
    head->next = newHead;
    return head;
}
void deleter(node *head, int i)
{
    int count = 0;
    node *temp = head;
    while (count < i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        return;
    }
    node *a = temp->next;
    node *b = a->next;
    temp->next = b; // deleteion
    delete a;       // need to de-allocate
}
node *insert(node *head, int i, int data)
{
    node *newNode = new node(data);
    int count = 0;
    node *temp = head;
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while (count < i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        return head; // when index entered is greater than size of linked list
    }
    newNode->next = temp->next; // insertion
    temp->next = newNode;
    return head;
}
int main()
{
    node *head = takeInput();
    deleter(head, 4);
    print(head);
    return 0;
}