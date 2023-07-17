#include <queue>
#include <vector>
vector<int> kSmallest(int arr[], int n, int k)
{
    // Write your code here
    vector<int> ans;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]); // assume the queue has k smallest elements
    }

    for (int j = k; j < n; j++)
    {
        if (arr[j] < pq.top()) // if a new element comes thats smaller than any element in the queue, replace the max with it
        {
            pq.pop();
            pq.push(arr[j]);
        }
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}