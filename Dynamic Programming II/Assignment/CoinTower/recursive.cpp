#include <bits/stdc++.h>
using namespace std;
// tle
bool aWin(int n, int x, int y)
{
    if (n == x || n == y || n == 1)
        return true;

    bool decreaseX = true;
    if (n > x)
    {
        decreaseX = aWin(n - x, x, y);
    }
    bool decreaseY = true;
    if (n > y)
    {
        decreaseY = aWin(n - y, x, y);
    }
    bool decrease1 = true;
    if (n > 1)
    {
        decrease1 = aWin(n - 1, x, y);
    }
    if (!decrease1 || !decreaseX || !decreaseY)
    {
        return true;
    }
    return false;
}

string findWinner(int n, int x, int y)
{
    // Write your code here
    // A moves first. can A win?
    if (aWin(n, x, y))
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