#include <bits/stdc++.h>
using namespace std;
long countWaysHelper(int *denominations, int ind, int target, int **memo)
{
    // base case
    if (ind == 0)
    {
        if (target % denominations[ind] == 0)
            return 1; // eg. [1 1 1] for three
        else
            return 0;
    }
    if (memo[ind][target] != -1)
        return memo[ind][target];

    long noTake = countWaysHelper(denominations, ind - 1, target, memo);
    long take = 0;
    if (denominations[ind] <= target)
    {
        take = countWaysHelper(denominations, ind, target - denominations[ind], memo);
    }
    memo[ind][target] = take + noTake;
    return take + noTake;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    // write your code here
    int **memo = new int *[numDenominations + 1];
    for (int i = 0; i < numDenominations + 1; i++)
    {
        memo[i] = new int[value + 1];
        for (int j = 0; j < value + 1; j++)
        {
            memo[i][j] = -1;
        }
    }

    return countWaysHelper(denominations, numDenominations - 1, value, memo);
}

// denominations : 1 2 3 4
// value: 4
// [1 1 1 1] [2 2] [ 1 3] [4] [2 1 1] return 5