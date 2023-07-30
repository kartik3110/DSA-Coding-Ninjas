#include <bits/stdc++.h>
using namespace std;

// return the max length of sub sequence of s and t
int lcsHelper(string s, string t, int **dp)
{
    int m = s.size();
    int n = t.size();
    if (m == 0 || n == 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];

    int ans;
    if (s[0] == t[0])
        ans = 1 + lcsHelper(s.substr(1), t.substr(1), dp);
    else
    {
        int a = lcsHelper(s.substr(1), t, dp);
        int b = lcsHelper(s, t.substr(1), dp);
        int c = lcsHelper(s.substr(1), t.substr(1), dp);

        ans = max(a, max(b, c));
    }
    dp[m][n] = ans;
    return ans;
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
            dp[i][j] = -1;
        }
    }
    return lcsHelper(s, t, dp);
}

int main()
{
    string s = "abcd";
    string t = "acb";
    cout << lcs(s, t);
}