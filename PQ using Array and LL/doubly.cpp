#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *insertAtEnd(node *head, int data)
{
    node *newNode = new node(data);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *tail = temp;
    tail->next = newNode;
    newNode->prev = tail;
}
int main()
{
    string x = "hello";
    stack<int> s1;
    for (int i = 0; i < 5; i++)
    {
        s1.push(x[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        char n = s1.top();
        x[i] = n;
        s1.pop();
    }
    cout << x;

    return 0;
}