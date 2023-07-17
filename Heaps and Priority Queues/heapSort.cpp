#include <iostream>
using namespace std;
void heapSort(int arr[], int n)
{
    // Write your code
    // 1. build a heap from array
    // 2. call removemin and put min at last of array
    int childIndex;
    for (int i = 1; i < n; i++)
    {
        childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
            {
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    int size = n;
    while (size > 1)
    {
        // call removeMin on array of size 'size'
        int temp = arr[0]; // min element
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        size--;

        // heapify the unsorted array
        int parentIndex = 0;
        int lci = (2 * parentIndex) + 1;
        int rci = lci + 1;
        while (lci < size)
        {
            int minIndex = parentIndex;
            if (arr[lci] < arr[minIndex])
            {
                minIndex = lci;
            }
            if (rci < size && arr[rci] < arr[minIndex])
            {
                minIndex = rci;
            }
            if (minIndex == parentIndex)
                break;
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            parentIndex = minIndex;
            lci = (2 * parentIndex) + 1;
            rci = lci + 1;
        }
    }
}
using namespace std;

int main()
{
    int size;
    cout << "Enter size ";
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    heapSort(input, size);

    for (int i = 0; i < size; i++)
        cout << input[i] << " ";

    delete[] input;
}
