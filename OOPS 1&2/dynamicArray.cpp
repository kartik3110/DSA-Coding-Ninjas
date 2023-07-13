#include <iostream>
using namespace std;
class dynamicArray
{
    int size, nextIndex;
    int *arr;

public:
    dynamicArray()
    {
        size = 5;
        nextIndex = 0;
        arr = new int[5];
    }
    void add(int element)
    {
        if (nextIndex >= size) // double the size of dynamic array
        {
            int *newArr = new int[2 * size];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }
            size *= 2;
            delete[] arr;
            arr = newArr;
        }
        arr[nextIndex] = element;
        nextIndex++;
    }
    void addParticular(int element, int index)
    {
        if (index == nextIndex)
        {
            add(element);
        }
        else if (index < nextIndex)
        {
            arr[index] = element;
        }
        else
        {
            return;
        }
    }
    int get(int index)
    {
        return arr[index];
    }
    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    dynamicArray arr;
    arr.add(10);
    arr.add(15);
    arr.add(16);
    arr.add(12);
    arr.add(13);
    arr.add(19);
    arr.add(11);
    arr.add(11);
    arr.addParticular(99, 4);
    arr.print();
    cout << arr.get(4);

    return 0;
}