#include <iostream>
#include "nodeClass.cpp"
using namespace std;
int findNode(node *head, int n)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    return -1;
}
int main()
{

    return 0;
}