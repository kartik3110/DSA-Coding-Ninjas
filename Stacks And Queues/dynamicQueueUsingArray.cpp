#include <iostream>
using namespace std;
class queue
{
    int *data;
    int size;
    int capacity;
    int nextIndex;
    int firstIndex;

public:
    queue()
    {
        capacity = 5;
        size = 0;
        nextIndex = 0;
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
            int *newData = new int[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++) // populate the new array in correct order
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j] = data[i];
                j++;
            }
            //      ANOTHER WAY TO POPULATE NEW ARRAY WITH JUST ONE LOOP:
            // int i = ((firstIndex + 1) % capacity);
            // int j = 1;
            // newData[0] = data[firstIndex];
            // while (i != firstIndex)
            // {
            //     newData[j] = data[i];
            //     j++;
            //     i = (i + 1) % capacity;
            // }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
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
            return; // queue empty.
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
