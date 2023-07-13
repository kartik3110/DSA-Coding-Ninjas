#include <iostream>
using namespace std;
#include "nodeClass.cpp"
node *midPoint(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next; // if fast is also head,we will find the 2nd mid in case of even.
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
node *merge(node *head1, node *head2)
{
    node *tail = NULL;
    node *head = NULL;
    if (head1->data <= head2->data)
    {
        head = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    if (head2 == NULL) // 2nd LL got exhausted
    {
        while (head1 != NULL)
        {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
    }
    else // 1st LL got exhausted
    {
        while (head2 != NULL)
        {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    return head;
}
node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *mid = midPoint(head);
    node *head2 = mid->next;
    mid->next = NULL; // now head is head1
    head = mergeSort(head);
    head2 = mergeSort(head2);
    return merge(head, head2);
}

int main()
{
    node *head1 = takeInput();
    node *head2 = takeInput();
    return 0;
}