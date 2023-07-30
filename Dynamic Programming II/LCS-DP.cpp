#include <bits/stdc++.h>
using namespace std;

// return the max length of sub sequence of s and t
int lcsHelper(string s, string t, int **dp)
{
    int m = s.size();
    int n = t.size();
    // i represents length of s
    // j represents length of t
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            int ans;
            if (s[m - i] == t[n - j])
            {
                ans = dp[i - 1][j - 1] + 1;
            }
            else
            {
                int a = dp[i - 1][j];
                int b = dp[i][j - 1];
                int c = dp[i - 1][j - 1];
                ans = max(a, max(b, c));
            }
            dp[i][j] = ans;
        }
    }
    return dp[m][n];
}
int lcs(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **dp = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    return lcsHelper(s, t, dp);
}

int main()
{
    string s = "abcd";
    string t = "acbc";
    cout << lcs(s, t);
}