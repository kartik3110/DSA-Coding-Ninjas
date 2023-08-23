#include <bits/stdc++.h>
using namespace std;
int countWaysToMakeChange(int denominations[], int n, int target)
{
    // write your code here
    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[target + 1];
        for (int t = 0; t < target + 1; t++)
        {
            if (t == 0)
                dp[i][t] = 1;
            if (i == 0 && t != 0)
                dp[0][t] = (t % denominations[0] == 0);
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int t = 1; t < target + 1; t++)
        {
            // sum of take and no take
            int noTake = dp[i - 1][t];
            int take = 0;
            if (denominations[i] <= t)
            {
                take = dp[i][t - denominations[i]];
            }
            dp[i][t] = take + noTake;
        }
    }
    return dp[n - 1][target];
}

// denominations : 1 2 3 4
// target: 4
// [1 1 1 1] [2 2] [ 1 3] [4] [2 1 1] return 5