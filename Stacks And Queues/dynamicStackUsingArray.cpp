#include <iostream>
#include <climits>
using namespace std;
class stack
{
    int *arr;
    int nextIndex;
    int capacity;

public:
    stack() // constructor
    {
        arr = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int element)
    {
        if (nextIndex == capacity)
        {	//double the capacity
            int *newArr = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[nextIndex] = element;
        nextIndex++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty";
            return INT_MIN;
        }
        nextIndex--;
        return arr[nextIndex];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "stack is empty";
            return INT_MIN;
        }
        return arr[nextIndex - 1];
    }
};
