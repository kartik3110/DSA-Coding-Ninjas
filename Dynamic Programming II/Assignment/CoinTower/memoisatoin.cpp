#include <bits/stdc++.h>
using namespace std;

bool aWin(int n, int x, int y, int *memo)
{
    if (n == x || n == y || n == 1)
        return true;

    if (memo[n] != -1)
        return memo[n];
    bool decreaseX = true, decreaseY = true, decrease1 = true;
    if (n > x)
    {
        decreaseX = aWin(n - x, x, y, memo);
    }
    if (n > y)
    {
        decreaseY = aWin(n - y, x, y, memo);
    }
    if (n > 1)
    {
        decrease1 = aWin(n - 1, x, y, memo);
    }
    if (!decrease1 || !decreaseX || !decreaseY)
    {
        memo[n] = 1;
        return true;
    }
    memo[n] = 0;
    return false;
}

string findWinner(int n, int x, int y)
{
    // A moves first. can A win?
    int *memo = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        memo[i] = -1;
    }

    if (aWin(n, x, y, memo))
    {
        return "Beerus";
    }
    return "Whis";
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y);
}