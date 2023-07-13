#include <iostream>
#include <climits>
using namespace std;

class item
{
public:
    int data;
    item *next;
    int prn; // priority number
    item(int data, int priority)
    {
        next = NULL;
        this->data = data;
        this->prn = priority;
    }
};
class queue
{
public:
    item *head = NULL;

    bool isEmpty()
    {
        return head == NULL;
    }

    void enqueue(int val, int pr)
    {
        item *newNode = new item(val, pr);
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
        item *prev = NULL;
        item *temp = head;
        int highestPriotity = INT_MIN;
        int priorValue;
        while (temp)
        {
            if (temp->prn > highestPriotity)
            {
                highestPriotity = temp->prn;
                priorValue = temp->data;
            }
            temp = temp->next;
        }
        return highestPriotity;
    }

    int dequeue()
    {
        int target = getMax();
        item *prev = NULL;
        item *temp = head;
        while (temp->prn != target)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) // when removing head
        {
            head = temp->next;
            delete temp;
            return temp->data;
        }
        prev->next = temp->next;
        delete temp;
        return temp->data;
    }
};

int main()
{
    queue my_queue;
    my_queue.enqueue(50, 1000);
    my_queue.enqueue(100, 100);
    my_queue.enqueue(20, 200);
    my_queue.enqueue(300, 300);
    my_queue.enqueue(10, 400);

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