#include <bits/stdc++.h>
using namespace std;
int kanpsack(int *weights, int *values, int n, int maxWeight)
{
    // w represents maximum weight allowed in dp[i][w]
    // dp[i][w] represents starting from i in the array, how much value can i take st its weight <= w.
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w < maxWeight + 1; w++)
        {
            dp[i] = new int[w + 1];
            if (i == n)
                dp[i][w] = 0;
            if (w == 0)
                dp[i][w] = 0;
        }
    }
    // 0 2 2 3 3
    // 0 2 2 3 3
    // 0 X 2 3 3     X == starting pt
    // 0 0 0 0 0
    //  i need value of max(dp[i+1] with current included and not included)
    //  ie dp[i+1][w] and values[i] + dp[i+1][w - weights[i]]
    for (int i = n - 1; i >= 0; i--)
    {
        for (int w = 1; w <= maxWeight; w++)
        {
            if (weights[i] > w)
                dp[i][w] = dp[i + 1][w];
            else
                dp[i][w] = max(dp[i + 1][w], values[i] + dp[i + 1][w - weights[i]]);
        }
    }
    return dp[n][maxWeight];
}
