#include <iostream>
using namespace std;
#include "nodeClass.cpp"
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

node *reverseLinkedListRec(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *temp = reverseLinkedListRec(head->next);
    // node* ans = temp;
    // while (temp->next != NULL)
    // {
    //     temp = temp->next;
    // }
    // temp->next = head;
    // head->next = NULL;
    // return ans;

    head->next->next = head;
    head->next = NULL;
    return temp;
}
int main()
{
    node *head1 = takeInput();
    return 0;
}