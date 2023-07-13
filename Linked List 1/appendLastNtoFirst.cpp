#include <iostream>
#include "nodeClass.cpp"
using namespace std;
node *appendLastNToFirst(node *head, int n) // append last n nodes to first
{
    node *slow = head;
    node *fast = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = head;
    head = slow->next;
    slow->next = NULL;

    return head;
}
node *removeDuplicates(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    node *fast = head;
    node *slow = head->next;
    while (fast != NULL)
    {
        if (fast->data == slow->data)
        {
            // delete
            slow->next = fast->next;
            delete fast;
            fast = slow->next;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return head;
}
int main()
{

    return 0;
}