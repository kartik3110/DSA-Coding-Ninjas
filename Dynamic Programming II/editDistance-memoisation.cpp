#include <bits/stdc++.h>
using namespace std;

int editDistanceHelper(string s1, string s2, int **dp)
{
    int m = s1.size();
    int n = s2.size();
    // Write your code here
    if (m == 0 || n == 0)
        return max(m, n);
    if (dp[m][n] != -1)
        return dp[m][n];
    int ans;
    if (s1[0] == s2[0])
        ans = editDistanceHelper(s1.substr(1), s2.substr(1), dp);
    else
    {
        // add
        int a = editDistanceHelper(s1.substr(1), s2, dp) + 1;
        // update
        int b = editDistanceHelper(s1.substr(1), s2.substr(1), dp) + 1;
        // delete
        int c = editDistanceHelper(s1, s2.substr(1), dp) + 1;
        ans = min(a, min(b, c));
    }
    dp[m][n] = ans;
    return ans;
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
            dp[i][j] = -1;
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