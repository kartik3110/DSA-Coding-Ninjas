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

bool isPalindrome(node *head)
{
    if (head->next == NULL)
    {
        return true;
    }
    node *current = head;
    node *prev = NULL; // never leave pointer un initialised
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    if (head->data == current->data)
    {
        prev->next = NULL;
        delete current;
        return isPalindrome(head->next);
    }
    else
        return false;
}
int main()
{
    node *head = takeInput();
    cout << isPalindrome(head);
    return 0;
}