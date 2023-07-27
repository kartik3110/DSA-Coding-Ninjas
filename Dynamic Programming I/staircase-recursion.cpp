// this code is only for reference to solving with recursion, will give TLE
#include <bits/stdc++.h>
using namespace std;

const long long int factor = 1000000007;

int staircase(int n)
{
    if (n == 3)
        return 4;
    if (n == 2)
        return 2;
    if (n == 1)
        return 1;
    int x = staircase(n - 1) % factor;
    int y = staircase(n - 2) % factor;
    int z = staircase(n - 3) % factor;
    return (((x + y) % factor) + z) % factor;
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