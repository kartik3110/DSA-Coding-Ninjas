#include <iostream>
using namespace std;
#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k)
{
    // Write your code here
    unordered_map<int, int> freq;
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (freq[arr[i] + k] > 0)
        {
            count += freq[arr[i] + k];
        }
        if (k && freq[arr[i] - k] > 0)
        {
            count += freq[arr[i] - k];
        }
        freq[arr[i]]++;
    }

    return count;
}