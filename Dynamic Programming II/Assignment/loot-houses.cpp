int maxMoneyLooted(int *arr, int n)
{
    // Write your code here
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = arr[0];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
    }
    return dp[n];
}