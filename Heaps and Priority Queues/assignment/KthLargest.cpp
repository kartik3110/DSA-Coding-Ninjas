#include <iostream>
#include <queue>
using namespace std;
int kthLargest(int *arr, int n, int k)
{
    // Write your code here
    priority_queue<int> pq;
    int ans;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (k--)
    {
        ans = pq.top();
        pq.pop();
    }
    return ans;
}