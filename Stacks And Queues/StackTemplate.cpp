#include <iostream>
#include <climits>
using namespace std;
template <typename T>
class stack
{
    T *arr;
    int nextIndex;
    int capacity;

public:
    stack() // constructor
    {
        arr = new T[4];
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
        {
            T *newArr = new T[capacity * 2];
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

    T pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty";
            return 0; // return 0 instead of intmin as 0 will work for all data types.
        }
        nextIndex--;
        return arr[nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "stack is empty";
            return 0;
        }
        return arr[nextIndex - 1];
    }
};