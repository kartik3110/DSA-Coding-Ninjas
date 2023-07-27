#include <bits/stdc++.h>
using namespace std;
// // DP
int minCountHelper(int n, int *arr)
{
    for (int i = 4; i <= n; i++)
    {
        int minimum = INT_MAX;
        int root = sqrt(i);
        for (int j = 1; j <= root; j++)
        {
            int ans = arr[i - j * j] + 1;
            minimum = min(ans, minimum);
            arr[i] = minimum;
        }
    }
    return arr[n];
}
int minCount(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    return minCountHelper(n, arr);
}

// MEMOISATION
//  int minCountHelper(int n, int *arr)
//  {
//      if (n <= 3)
//          return n;
//      if (arr[n] != -1)
//      {
//          return arr[n];
//      }
//      // Write your code here
//      int root = sqrt(n);
//      int minimum = INT_MAX;
//      for (int i = 1; i <= root; i++)
//      {
//          int ans = minCountHelper(n - i * i, arr) + 1;
//          minimum = min(ans, minimum);
//          arr[n] = minimum;
//      }
//      return minimum;
//  }
//  int minCount(int n)
//  {
//      int *arr = new int[n + 1];
//      for (int i = 0; i < n + 1; i++)
//      {
//          arr[i] = -1;
//      }
//      return minCountHelper(n, arr);
//  }

// recursion (TLE)
//  int minCount(int n)
//  {
//      if (n <= 3)
//          return n;
//      // Write your code here
//      int root = sqrt(n);
//      int minimum = INT_MAX;
//      for (int i = 1; i <= root; i++)
//      {
//          int ans = minCount(n - i * i) + 1;
//          minimum = min(ans, minimum);
//      }
//      return minimum;
//  }