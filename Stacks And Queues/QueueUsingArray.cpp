#include <iostream>
using namespace std;
class queue
{
    int *data;
    int size;//no. of actual elements in the array
    int capacity;
    int nextIndex;
    int firstIndex;

public:
    queue(int totalSize)
    {
        capacity = totalSize;
        nextIndex = 0;
        size = 0;
        firstIndex = -1;
        data = new int[capacity];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void enqueue(int element)
    {
        if (size == capacity) // nextIndex >= capacity does not work as we are filling data circularly in array.
        {
        	cout<<"not enough space in queue.";
            return; 
        }
        data[nextIndex] = element;
        if (isEmpty())
        {
            firstIndex = 0;
        }
        nextIndex = (nextIndex + 1) % capacity;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
        	cout<< "queue empty";
            return; 
        }
        firstIndex = (firstIndex + 1) % capacity;
        size--;
    }

    int front()
    {
        if (isEmpty())
        {
            return 0; // queue empty.
        }

        return data[firstIndex];
    }
};
