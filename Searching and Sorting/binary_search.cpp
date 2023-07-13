int findUnique(int *arr, int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
            // RIGHT CODE
        }

        if (count == 1)
        {
            return arr[i];
            count = 0;
        }
        else
        {
            count = 0;
        }
    }
}

#include <iostream>
using namespace std;
int binarySearch(int *input, int num, int val)
{
    int start = 0;
    int end = num - 1;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (val > input[mid])
        {
            start = mid + 1;
        }
        else if (val < input[mid])
        {
            end = mid - 1;
        }
        else
            return mid;
    }
    return -1;
}
int main()
{
    int size;
    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; ++i)
    {
        cin >> input[i];
    }

    int t;
    cin >> t;

    while (t--)
    {
        int val;
        cin >> val;
        cout << binarySearch(input, size, val) << endl;
    }

    delete[] input;
    return 0;
}
