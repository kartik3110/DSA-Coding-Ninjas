#include <bits/stdc++.h>
using namespace std;
int knapsack(int *wt, int *val, int n, int W)
{
    // w represents maximum weight allowed in dp[i][w]
    // dp[i][w] represents starting from i in the array, how much value can i take such that its weight <= w.
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[W + 1];
        for (int w = 0; w <= W; w++)
        {
            if (i == n || w == 0)
                dp[i][w] = 0;
        }
    }
    // 0 2 2 3 3
    // 0 2 2 3 3
    // 0 X 2 3 3     X == starting pt
    // 0 0 0 0 0
    //  i need value of max(dp[i+1] with current included and not included)
    //  ie dp[i+1][w] and val[i] + dp[i+1][w - wt[i]]
    for (int i = n - 1; i >= 0; i--)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i] > w)
                dp[i][w] = dp[i + 1][w];
            else
                dp[i][w] = max(dp[i + 1][w], val[i] + dp[i + 1][w - wt[i]]);
        }
    }
    return dp[0][W];
}