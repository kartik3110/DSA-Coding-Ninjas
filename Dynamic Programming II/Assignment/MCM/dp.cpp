#include <climits>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(int *arr, int n)
{
    // Write your code here
    int **operations = new int *[n + 1];
    for (int s = 0; s < n + 1; s++)
    {
        operations[s] = new int[n + 1];
        for (int e = 0; e < n + 1; e++)
        {
            if (e - s <= 1)
            {
                operations[s][e] = 0;
            }
        }
    }

    for (int len = 2; len <= n; len++)
    {
        for (int s = 0, e = len; s <= n - len; s++, e++) // diagonal traversal
        {
            operations[s][e] = INT_MAX;
            for (int k = s + 1; k < e; k++)
            {
                int ops = operations[s][k] + operations[k][e] + (arr[s] * arr[k] * arr[e]);
                operations[s][e] = min(ops, operations[s][e]);
            }
        }
    }

    return operations[0][n];
}