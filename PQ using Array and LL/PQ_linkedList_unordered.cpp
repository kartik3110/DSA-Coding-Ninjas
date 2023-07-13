#include <iostream>
#include <climits>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        next = NULL;
        this->data = data;
    }
};
class queue
{
public:
    node *head = NULL;

    bool isEmpty()
    {
        return head == NULL;
    }

    void enqueue(int val)
    {
        node *newNode = new node(val);
        if (head)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        head = newNode;
    }

    int getMax()
    {
        node *prev = NULL;
        node *temp = head;
        int highest = INT_MIN;
        while (temp)
        {
            if (temp->data > highest)
            {
                highest = temp->data;
            }
            temp = temp->next;
        }
        return highest;
    }

    int dequeue()
    {
        int targetData = getMax();
        node *prev = NULL;
        node *temp = head;
        while (temp->data != targetData)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) // when removing head
        {
            head = temp->next;
            delete temp;
            return targetData;
        }
        prev->next = temp->next;
        delete temp;
        return targetData;
    }
};

int main()
{
    queue my_queue;
    my_queue.enqueue(50);
    my_queue.enqueue(100);
    my_queue.enqueue(20);
    my_queue.enqueue(300);
    my_queue.enqueue(10);

    cout << "The elements in the priority queue are:(ascending) \n";
    while (!my_queue.isEmpty())
    {
        // print the element at the top

        cout << my_queue.dequeue(); // highest priority element is at the top

        cout << "\n";
    }
    cout << "\n";
    return 0;
}