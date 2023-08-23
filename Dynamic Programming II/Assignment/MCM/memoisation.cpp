// interviewers will accept this solution and not make you write the tabulation approach, but on online platforms, might get rejected
#include <climits>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int mcm(int *p, int s, int e, int **operations)
{
    // k is where partition happens (take k in which min operations happen)
    // int k = s+1 se leke e-1 tk ho skta hai
    // k = s+ 1, bracket is like (A1)*(A2 A3 A4 A5 An)

    if (e - s == 1) // only one matrix
    {
        return 0;
    }
    if (operations[s][e] != -1)
    {
        return operations[s][e];
    }
    int minOperations = INT_MAX;
    // (take k in which min operations happen)
    for (int k = s + 1; k < e; k++)
    {
        int ops = mcm(p, s, k, operations) + mcm(p, k, e, operations) + (p[s] * p[k] * p[e]);
        minOperations = min(ops, minOperations);
    }
    operations[s][e] = minOperations;
    return minOperations;
}
int matrixChainMultiplication(int *arr, int n)
{
    // Write your code here
    int **operations = new int *[n];
    for (int s = 0; s < n; s++)
    {
        operations[s] = new int[n + 1];
        for (int e = 0; e < n + 1; e++)
        {
            operations[s][e] = -1;
        }
    }

    return mcm(arr, 0, n, operations);
}