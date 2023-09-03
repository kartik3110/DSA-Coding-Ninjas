#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int> &arr, int l, int r)
{
    vector<int> temp;
    int mid = (l + r) / 2;
    int right = mid + 1;
    int left = l;
    while (left <= mid && right <= r)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= r)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // arr = temp; cant be done as their sizes are different.

    int i = 0;
    for (int k = l; k <= r; k++)
    {
        arr[k] = temp[i];
        i++;
    }
}
void mergeSort(vector<int> &arr, int l, int r)
{
    // Write Your Code Here
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    mergeSortedArrays(arr, l, r);
}