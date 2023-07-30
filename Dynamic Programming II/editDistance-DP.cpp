#include <bits/stdc++.h>
using namespace std;

int editDistanceHelper(string s1, string s2, int **dp)
{
    int m = s1.size();
    int n = s2.size();
    // Write your code here
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[m - i] == s2[n - j])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }
    return dp[m][n];
}

int editDistance(string s1, string s2)
{
    // Write your code here
    int m = s1.size();
    int n = s2.size();
    int **dp = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            if (j == 0)
                dp[i][j] = i;
        }
    }
    return editDistanceHelper(s1, s2, dp);
}
int main()
{
    string s = "good";
    string t = "godbye";
    cout << editDistance(s, t);
}