#include <iostream>
using namespace std;
#include <unordered_map>
int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    // subarray question -> use prefix sum map
    // if 2 prefix sums are equal,subarray bw them sums to 0
    unordered_map<int, int> prefixSum;
    int currSum = 0;
    int count = 0;
    prefixSum[0] = -1;
    for (int i = 0; i < n; i++)
    {
        int start;
        currSum += arr[i];
        if (prefixSum.count(currSum) > 0)
        {
            start = prefixSum[currSum];
            count = max(count, i - start);
        }
        else
            prefixSum[currSum] = i;
    }
    return count;
}