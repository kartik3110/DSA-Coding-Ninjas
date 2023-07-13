#include <iostream>
// s = start; e = end;
using namespace std;
int partition(int *input, int s, int e)
{
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (input[i] <= input[s])
        {
            count++;
        }
    }
    int pi = count + s;
    // swapping
    int temp = input[pi];
    input[pi] = input[s];
    input[s] = temp;

    int i = s;
    int j = e;

    while (i < pi && j > pi)
    {
        if (input[i] >= input[pi])
        {
            if (input[j] < input[pi])
            {
                // swap
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
                i++;
                j--;
            }
            else
            {
                j--;
            }
        }
        else
        {
            i++;
        }
    }
    return pi;
}
void myQuickSort(int *input, int s, int e) // recursive
{
    if (s >= e) // base case
    {
        return;
    }
    int pivotIndex = partition(input, s, e);
    cout << pivotIndex;
    myQuickSort(input, s, pivotIndex - 1);
    myQuickSort(input, pivotIndex + 1, e);
}

void quickSort(int *input, int size)
{
    myQuickSort(input, 0, size - 1);
}

int main()
{
    int input[7] = {9, 5, 8, 10, 3, 6, 16};
    int n = 7;
    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}