#include <bits/stdc++.h>
using namespace std;
// 0   0   0
// 0   0   0
// 0   0   0
// DP
int minCostPath(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    output[m - 1][n - 1] = input[m - 1][n - 1];
    // LAST ROW
    for (int c = n - 2; c >= 0; c--)
    {
        output[m - 1][c] = output[m - 1][c + 1] + input[m - 1][c];
    }
    // last column
    for (int r = m - 2; r >= 0; r--)
    {
        output[r][n - 1] = output[r + 1][n - 1] + input[r][n - 1];
    }
    // rest of array
    for (int r = m - 2; r >= 0; r--)
    {
        for (int c = n - 2; c >= 0; c--)
        {
            output[r][c] = min(output[r + 1][c + 1], min(output[r][c + 1], output[r + 1][c])) + input[r][c];
        }
    }
    return output[0][0];
}

// MEMOIZATION    TIME, SPACE -> O(M*N)
// int minCostHelper(int **input, int m, int n, int startRow, int startCol, int **minCosts)
// {
//     if (startRow == m - 1 && startCol == n - 1)
//         return input[m - 1][n - 1];

//     if (minCosts[startRow][startCol] != -1)
//         return minCosts[startRow][startCol];
//     int down = INT_MAX;
//     int right = INT_MAX;
//     int diagonal = INT_MAX;
//     if (startRow + 1 < m)
//     {
//         down = minCostHelper(input, m, n, startRow + 1, startCol, minCosts);
//     }
//     if (startCol + 1 < n)
//     {
//         right = minCostHelper(input, m, n, startRow, startCol + 1, minCosts);
//     }
//     if (startRow + 1 < m && startCol + 1 < n)
//     {
//         diagonal = minCostHelper(input, m, n, startRow + 1, startCol + 1, minCosts);
//     }
//     int ans = min(down, min(right, diagonal)) + input[startRow][startCol];
//     minCosts[startRow][startCol] = ans;
//     return ans;
// }
// int minCostPath(int **input, int m, int n)
// {
//     int **arr = new int *[m];
//     for (int i = 0; i < m; i++)
//     {
//         arr[i] = new int[n];
//     }
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             arr[i][j] = -1;
//         }
//     }

//     return minCostHelper(input, m, n, 0, 0, arr);
// }

// RECURSION BRUTE FORCE
// int minCostHelper(int **input, int m, int n, int startRow, int startCol)
// {
//     if (startRow == m - 1 && startCol == n - 1)
//         return input[m - 1][n - 1];
//     int down = INT_MAX;
//     int right = INT_MAX;
//     int diagonal = INT_MAX;
//     if (startRow + 1 < m)
//     {
//         down = minCostHelper(input, m, n, startRow + 1, startCol);
//     }
//     if (startCol + 1 < n)
//     {
//         right = minCostHelper(input, m, n, startRow, startCol + 1);
//     }
//     if (startRow + 1 < m && startCol + 1 < n)
//     {
//         diagonal = minCostHelper(input, m, n, startRow + 1, startCol + 1);
//     }
//     return min(down, min(right, diagonal)) + input[startRow][startCol];
// }
// int minCostPath(int **input, int m, int n)
// {
//     return minCostHelper(input, m, n, 0, 0, arr);
// }
