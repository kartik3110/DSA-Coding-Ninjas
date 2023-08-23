#include <climits>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int mcm(int *p, int s, int e)
{
    // k is where partition happens (take k in which min operations happen)
    // int k = s+1 se leke e-1 tk ho skta hai
    // k = s+ 1, bracket is like (A1)*(A2 A3 A4 A5 An)

    if (e - s == 1) // only one matrix
    {
        return 0;
    }
    int minOperations = INT_MAX;
    // (take k in which min operations happen)
    for (int k = s + 1; k < e; k++)
    {
        int operations = mcm(p, s, k) + mcm(p, k, e) + (p[s] * p[k] * p[e]);
        minOperations = min(operations, minOperations);
    }
    return minOperations;
}
int matrixChainMultiplication(int *arr, int n)
{
    // Write your code here

    return mcm(arr, 0, n);
}