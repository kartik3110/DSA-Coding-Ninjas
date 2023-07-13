#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int *input, int size)
{
    int temp[size];
    for (int j = 0; j < size; j++)
    {
        temp[j] = 1;
    }
    int start = 0;
    int end = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == 0)
        {
            temp[start] = 0;
            start++;
        }
        else if (input[i] == 2)
        {
            temp[end] = 2;
            end--;
        }
    }
    for (int k = 0; k < size; k++)
    {
        input[k] = temp[k];
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;

        cin >> size;
        int *arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }

        sort012(arr, size);

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        delete[] arr;
        cout << endl;
    }

    return 0;
}