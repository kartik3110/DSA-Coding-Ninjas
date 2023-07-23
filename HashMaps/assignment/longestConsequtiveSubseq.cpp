#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, bool> isPresent;
    unordered_map<int, int> indexOf;
    for (int i = 0; i < n; i++)
    {
        isPresent[arr[i]] = true; // marks there is an element arr[i]
        indexOf[arr[i]] = i;
    }
    int maxCount = 0;
    int startIndex = n;
    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        int count = 0;
        int startOfCurrentSeq = i;
        while (isPresent[val + 1])
        {
            count++;
            val++;
            isPresent[val] = false;
        }
        val = arr[i];
        while (isPresent[val - 1])
        {
            count++;
            val--;
            isPresent[val] = false;
            startOfCurrentSeq = indexOf[val];
        }
        if (count > maxCount || (count == maxCount && startOfCurrentSeq < startIndex))
        {
            startIndex = startOfCurrentSeq;
            maxCount = count;
        }
    }
    vector<int> ans;
    ans.push_back(arr[startIndex]);
    if (maxCount)
    {
        ans.push_back(arr[startIndex] + maxCount);
    }
    return ans;
}

// vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
//   // Your Code goes here
//   unordered_map<int, int> m;
//   vector<int> ans;
//   for (int i = 0; i < n; i++)
//     m[arr[i]] = i;
//   for (int i = 0; i < n; i++) {
//     vector<int> temp;
//     // Find the starting point for the increasing sequence
//     if (m.count(arr[i] - 1) == 0) {
//       temp.push_back(arr[i]);
//       int t = 1;
//       while (m.count(arr[i] + t)) {
//         temp.push_back(arr[i] + t);
//         t++;
//       }
//       if (temp.size() > ans.size())
//         ans = temp;
//     }
//   }
//   int n1 = ans[0];
//   int n2 = ans[ans.size() - 1];
//   ans.clear();
//   ans.push_back(n1);
//   ans.push_back(n2);
//   return ans;
// }