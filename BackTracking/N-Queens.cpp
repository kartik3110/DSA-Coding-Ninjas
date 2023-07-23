#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int board[11][11]; // cant use vector as its not index based
int n;             // size
vector<vector<int>> ans;

bool isValidSquare(int rowInd, int colInd)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][colInd] == 1)
            return false;
    }
    // check left diagonal
    int r = rowInd - 1;
    int c = colInd - 1;
    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 1)
            return false;
        r--;
        c--;
    }
    // check right diagonal
    r = rowInd - 1;
    c = colInd + 1;
    while (r >= 0 && c < n)
    {
        if (board[r][c] == 1)
            return false;
        r--;
        c++;
    }
    return true;
}

void solve(int rowIndex)
{
    if (rowIndex == n)
    { // add a vector to ans
        vector<int> solution;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                solution.push_back(board[i][j]);
        }
        ans.push_back(solution);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isValidSquare(rowIndex, i))
        {
            board[rowIndex][i] = 1;
            solve(rowIndex + 1);
            // being here means A call returned with no solution OR returned after printing a solution.Either way need to remove the current queen.
            // therefore I need to remove the original solution & let the for loop go forward.
            board[rowIndex][i] = 0;
        }
    }
    return;
}
vector<vector<int>> nQueens(int size)
{
    memset(board, 0, 11 * 11 * sizeof(int)); // initialise board with 0
    n = size;
    solve(0);
    return ans;
}
