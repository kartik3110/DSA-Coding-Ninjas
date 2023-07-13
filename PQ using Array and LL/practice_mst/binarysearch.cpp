#include <iostream>
using namespace std;
int binarysearchRec(int *arr, int s, int e, int x)
{
    int mid = (s + e) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] <= x)
    {
        return binarysearchRec(arr, mid + 1, e, x);
    }
    else if (arr[mid] >= x)
    {
        return binarysearchRec(arr, s, mid - 1, x);
    }
}
int binarysearch(int *arr, int size, int x)
{
    int s = 0;
    int e = size - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (x > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int x = 8;
    cout << binarysearchRec(arr, 0, size - 1, x);

    return 0;
}