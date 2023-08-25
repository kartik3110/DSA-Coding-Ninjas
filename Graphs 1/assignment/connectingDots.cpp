#include <bits/stdc++.h>
using namespace std;

const int directions[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool isValidPoint(int r, int c, int numRows, int numCols)
{
    return r < numRows && c < numCols && r >= 0 && c >= 0;
}

bool hasCycleHelper(vector<vector<char>> &board, int rows, int cols, int r, int c, int startRow, int startCol, int cycleSize, bool **visited)
{
    // if (visited[r][c] && r == startRow && c == startCol && cycleSize >= 4)
    // {
    //     // have come back to the first cell
    //     return true;
    // }
    visited[r][c] = true;
    // cout<<cycleSize<<endl;
    bool ans;
    for (int i = 0; i < 4; i++)
    {
        int newRow = r + directions[i][0];
        int newCol = c + directions[i][1];
        if (isValidPoint(newCol, newRow, rows, cols) && !visited[newRow][newCol] && board[newCol][newRow] == board[r][c])
        {
            ans = hasCycleHelper(board, rows, cols, newRow, newCol, startRow, startCol, cycleSize + 1, visited);
            if (ans)
                return true;
        }
        if (isValidPoint(newRow, newCol, rows, cols) && visited[newRow][newCol] && newRow == startRow && newCol == startCol && cycleSize >= 4)
            return true;
    }
    // because if we dont do this, a wrong starting point will visit all the points and the correct starting point wont be able to find them
    visited[r][c] = false;
    return ans;
}

bool hasCycle(vector<vector<char>> &board, int rows, int cols)
{
    bool **visited = new bool *[rows];
    for (int i = 0; i < rows; i++)
    {
        visited[i] = new bool[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!visited[i][j])
            {
                // dfs
                if (hasCycleHelper(board, rows, cols, i, j, i, j, 1, visited))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}