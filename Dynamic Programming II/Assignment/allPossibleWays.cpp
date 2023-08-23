#include <cmath>
const int MOD = 1000000007;
int getWaysHelper(int a, int b, int start, int **memo)
{
    // base case
    if (a == 0)
        return 1;
    if (pow(start, b) > a || a < 0)
    {
        return 0;
    }
    if (memo[a][start] != -1)
        return memo[a][start];
    // recursion
    int x = getWaysHelper(a - pow(start, b), b, start + 1, memo) % MOD;
    int y = getWaysHelper(a, b, start + 1, memo) % MOD;
    int ans = (x + y) % MOD;
    memo[a][start] = ans;
    return ans;
}
int getAllWays(int a, int b)
{
    int **memo = new int *[a + 1];
    for (int i = 0; i <= a; i++)
    {
        memo[i] = new int[a + 1];
        for (int j = 0; j <= a; j++)
        {
            memo[i][j] = -1;
        }
    }
    return getWaysHelper(a, b, 1, memo);
}

// a = 10
// b = 2
// res = 0
// 1^2
// 10 - 1
// solve again for 9 this time
// ^ shall return 0 or 1 .
// add it to ans.
// now solve for 10 - 2^2
// ie solve for 6
// whatever ways(6) returns ---> will be 0 or 1, add that to the ans

// 1. recursion on smaller problems -> high time complexity
// 2. recursion but memoised
// 3. dynamic programming -> solve for the smallest problem first and then keep building up towards main problem
// // 3 is best
