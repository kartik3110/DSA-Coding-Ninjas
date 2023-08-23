#include <bits/stdc++.h>
using namespace std;

// WATCH HINT, VERY USEFUL
int findMaxSquareWithAllZeros(int **arr, int rows, int cols)
{
    // Write your code here
    int **dp = new int *[rows];
    for (int r = 0; r < rows; r++)
    {
        dp[r] = new int[cols];
        for (int c = 0; c < cols; c++)
        {
            if (c == 0 || r == 0) // base case, first row and column
            {
                dp[r][c] = arr[r][c] ^ 1;
            }
        }
    }
    for (int r = 1; r < rows; r++)
    {
        for (int c = 1; c < cols; c++)
        {
            if (arr[r][c] == 1)
                dp[r][c] = 0;
            else
                dp[r][c] = 1 + min(dp[r - 1][c - 1], min(dp[r - 1][c], dp[r][c - 1]));
        }
    }
    int maxLengthOfSquare = 0;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            maxLengthOfSquare = max(maxLengthOfSquare, dp[r][c]);
        }
    }
    return maxLengthOfSquare;
}