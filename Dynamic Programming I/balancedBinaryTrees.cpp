#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
// DP
int balancedBtsHelper(int h, int *arr)
{

    if (arr[h] != -1)
        return arr[h];

    for (int i = 2; i < h + 1; i++)
    {
        int temp1 = (int)(((long)arr[i - 1] * arr[i - 1]) % mod); // makes a long buffer which stores arr[i-1]*arr[i-1] , then after % , store in a int
        int temp2 = (int)((2 * (long)arr[i - 1] * arr[i - 2]) % mod);
        int ans = (int)(((long)temp1 + temp2) % mod);
        arr[i] = ans;
    }

    return arr[h];
}
int balancedBTs(int h)
{
    int *arr = new int[h + 1];
    for (int i = 0; i < h + 1; i++)
    {
        arr[i] = -1;
    }
    arr[0] = 1;
    arr[1] = 1;
    return balancedBtsHelper(h, arr);
}

// MEMOISATION(O(N))
// int balancedBtsHelper(int h, int *arr)
// {

//     if (h <= 1)
//         return 1;

//     if (arr[h] != -1)
//         return arr[h];

//     int x = balancedBtsHelper(h - 1, arr);
//     int y = balancedBtsHelper(h - 2, arr);

//     int temp1 = (int)(((long)x * x) % mod); // makes a long buffer which stores x*x , then after % , store in a int
//     int temp2 = (int)((2 * (long)x * y) % mod);
//     int ans = (int)(((long)temp1 + temp2) % mod);
//     arr[h] = ans;
//     return ans;
// }
// int balancedBTs(int h)
// {
//     int *arr = new int[h + 1];
//     for (int i = 0; i < h + 1; i++)
//     {
//         arr[i] = -1;
//     }
//     return balancedBtsHelper(h, arr);
// }

// TIME COMPLEXITY 2^N - RECURSION
// int balancedBTs(int n)
// {
//     if (n <= 1)
//         return 1;

//     int x = balancedBTs(n - 1);
//     int y = balancedBTs(n - 2);

// int temp1 = (int)(((long)x * x) % mod); // makes a long buffer which stores x*x , then after % , store in a int
// int temp2 = (int)((2 * (long)x * y) % mod);
// int ans = (int)(((long)temp1 + temp2) % mod);

//     return ans;
// }