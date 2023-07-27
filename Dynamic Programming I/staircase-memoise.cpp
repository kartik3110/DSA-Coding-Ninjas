// this code is only for reference to solving with memoisation
#include <bits/stdc++.h>
using namespace std;

const long long int factor = 1000000007;

int staircaseHelper(int n, int *arr)
{
    if (n == 3)
        return 4;
    if (n == 2)
        return 2;
    if (n == 1)
        return 1;
    if (arr[n] != -1)
        return arr[n];
    int x = staircaseHelper(n - 1, arr) % factor;
    int y = staircaseHelper(n - 2, arr) % factor;
    int z = staircaseHelper(n - 3, arr) % factor;
    arr[n] = (((x + y) % factor) + z) % factor;
    return arr[n];
}

int staircase(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }
    return staircaseHelper(n, arr);
}
int main()
{
    // take input from the user.
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << staircase(n) << endl;
    }

    return 0;
}