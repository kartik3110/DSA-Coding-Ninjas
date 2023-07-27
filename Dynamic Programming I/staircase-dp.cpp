#include <bits/stdc++.h>
using namespace std;

const long long int factor = 1000000007;

int staircaseHelper(int n, int *arr)
{
    for (int i = 4; i < n + 1; i++)
    {
        int x = arr[i - 1] % factor;
        int y = arr[i - 2] % factor;
        int z = arr[i - 3] % factor;
        // cant do this: bcz need to mod after every addition.
        //  arr[i] = (x + y + z) % factor
        arr[i] = (((x + y) % factor) + z) % factor;
    }
    return arr[n];
}

int staircase(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
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