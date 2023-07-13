#include <iostream>
#include <climits>
using namespace std;
// no need to make item class. just assume the value to be same as priority number and make a simple array of integers.
class item
{
public:
    int value;
    int priority;
};

class queue
{
public:
    item arr[1000];
    int nextIndex = 0;

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void enqueue(int data, int prt)
    {
        arr[nextIndex].value = data;
        arr[nextIndex].priority = prt;
        nextIndex++;
    }

    int getMax() // return highest priority element
    {
        int highestPriority = INT_MIN;
        int highestIndex = -1;
        for (int i = 0; i < nextIndex; i++)
        {
            if (arr[i].priority > highestPriority)
            {
                highestPriority = arr[i].priority;
                highestIndex = i;
            }
        }
        return highestIndex;
    }

    int deleteMax()
    {
        int index = getMax();
        int ans = arr[index].value;
        for (int i = index; i < nextIndex; i++)
        {
            arr[i] = arr[i + 1];
        }
        nextIndex--;
        return ans;
    }

    int getMin() // return lowest priority element
    {
        int lowestPriority = INT_MAX;
        int lowestIndex = -1;
        for (int i = 0; i < nextIndex; i++)
        {
            if (arr[i].priority < lowestPriority)
            {
                lowestPriority = arr[i].priority;
                lowestIndex = i;
            }
        }
        return lowestIndex;
    }

    int deleteMin()
    {
        int index = getMin();
        int ans = arr[index].value;
        for (int i = index; i < nextIndex; i++)
        {
            arr[i] = arr[i + 1];
        }
        nextIndex--;
        return ans;
    }
};

int main()
{
    queue my_queue;
    my_queue.enqueue(50, 50);
    my_queue.enqueue(100, 100);
    my_queue.enqueue(20, 20);
    my_queue.enqueue(300, 300);
    my_queue.enqueue(10, 10);

    cout << "The elements in the priority queue are:(ascending) \n";
    while (!my_queue.isEmpty())
    {
        // print the element at the top

        cout << my_queue.deleteMax(); // highest priority element is at the top

        cout << "\n";
    }
    cout << "\n";

    cout << "The elements in the priority queue are:(descending) \n";
    while (!my_queue.isEmpty())
    {
        // print the element at the top

        cout << my_queue.deleteMin(); // highest priority element is at the top

        cout << "\n";
    }

    return 0;
}