#include <iostream>
#include <queue>
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    // Write your code here
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq; // min priority queue
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i]->size(); j++)
        {
            pq.push(input[i]->at(j));
        }
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}