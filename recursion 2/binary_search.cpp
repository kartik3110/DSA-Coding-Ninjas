#include <iostream>
using namespace std;
int mySearch(int *input, int si, int ei, int x)
{
    int mid = (si + ei) / 2;
    if (si > ei)
    {
        return -1;
    }
    if (input[mid] == x)
    {
        return mid;
    }
    else if (x > input[mid])
    {
        return mySearch(input, mid + 1, ei, x);
    }
    else if (x < input[mid])
    {
        return mySearch(input, si, mid - 1, x);
    }
}
int binarySearch(int *input, int size, int x)
{
    return mySearch(input, 0, size - 1, x);
}
int main()
{
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8; // size
    int x = 7;
    cout << binarySearch(arr, n, x);
    return 0;
}