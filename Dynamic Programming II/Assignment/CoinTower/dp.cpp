#include <bits/stdc++.h>
using namespace std;

// x ^ 1 = !x
string findWinner(int n, int x, int y)
{
    // A moves first. can A win?
    int *dp = new int[n + 1];

    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || i == x || i == y)
        {
            dp[i] = 1;
            continue;
        }
        dp[i] = dp[i - 1] ^ 1; // can always take 1 coin. will change it if taking x or y is better.

        if (i > x)
        {
            dp[i] = max(dp[i - x] ^ 1, dp[i]); // if he loses on taking 1 coin and wins on taking x, dp[i] will still be 1
        }
        if (i > y)
        {
            dp[i] = max(dp[i - y] ^ 1, dp[i]);
        }
    }
    return (dp[n] == 1) ? "Beerus" : "Whis";
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y);
}