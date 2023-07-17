#include <iostream>
#include <queue>
using namespace std;
int buyTicket(int *arr, int n, int k)
{
    // Write your code here
    priority_queue<int> pq;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]); // contains priorities
        q.push(i);       // contains indices
    }
    int time = 0;
    while (true)
    {
        if (arr[q.front()] >= pq.top())
        {
            // give ticket
            if (k == q.front())
            {
                return ++time;
            }
            q.pop();
            pq.pop();
            time++;
        }
        else
        {
            // send to back
            q.push(q.front());
            q.pop();
        }
    }
}
int buyTicket(int *arr, int n, int k)
{
    // Write your code here
    priority_queue<int> pq;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]); // contains priorities
        q.push(i);       // contains indices
    }
    int time = 0;
    while (true)
    {
        if (arr[q.front()] >= pq.top())
        {
            // give ticket
            if (k == q.front())
            {
                return ++time;
            }
            q.pop();
            pq.pop();
            time++;
        }
        else
        {
            // send to back
            q.push(q.front());
            q.pop();
        }
    }
}