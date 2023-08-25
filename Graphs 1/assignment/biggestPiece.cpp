#include <bits/stdc++.h>
using namespace std;

const int directions[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}}; // L, U, D, R

bool isValidPoint(int r, int c, int n)
{
    if (r >= 0 && c >= 0 && r < n && c < n)
        return true;
    return false;
}
// 1 1 1
// 0 1 0
// 1 1 0

int getPiece(vector<vector<int>> &cake, int n, int r, int c, bool **visited, int currentSize = 0)
{
    visited[r][c] = true;
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        int newRow = r + directions[i][0];
        int newCol = c + directions[i][1];
        if (isValidPoint(newRow, newCol, n) && cake[newRow][newCol] == 1 && !visited[newRow][newCol])
        {
            ans += getPiece(cake, n, newRow, newCol, visited);
        }
    }
    // visited[r][c] = false;
    return ans + 1;
    // will return 1 even if nothing was found in the for loop. this is OK bcz the function is only called when a 1 is found. so it will return a min size of 1
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    // cake is n*n matrix
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
    }

    int maxPiece = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 && !visited[i][j])
            {
                // do a dfs from (i,j)
                int piece = getPiece(cake, n, i, j, visited);
                maxPiece = max(maxPiece, piece);
            }
        }
    }
    return maxPiece;
}