#include <bits/stdc++.h>
using namespace std;
int currentCharIndex = 0;
char target[11] = {'C', 'O', 'D', 'I', 'N', 'G', 'N', 'I', 'N', 'J', 'A'};
int directions[8][2] = {{1, 1}, {0, 1}, {1, 0}, {1, -1}, {-1, 1}, {-1, -1}, {0, -1}, {-1, 0}};

bool isValidPoint(int r, int c, int numRows, int numCols)
{
    if (r < numRows && c < numCols && r >= 0 && c >= 0)
    {
        return true;
    }
    // goes out of board
    return false;
}
bool hasPath(vector<vector<char>> &board, int numRows, int numCols, int rowStart, int colStart, bool **visited, int patternIndex)
{
    if (patternIndex >= 11)
    {
        return true; // all characters were found
    }

    visited[rowStart][colStart] = true;

    bool ans = false;
    // check to see if any of the 8 directions have the next index of pattern
    for (int i = 0; i < 8; i++)
    {
        int newRowStart = rowStart + directions[i][0];
        int newColStart = colStart + directions[i][1];
        if (isValidPoint(newRowStart, newColStart, numRows, numCols) && !visited[newRowStart][newColStart] && board[newRowStart][newColStart] == target[patternIndex])
        {
            // means next letter was found in one of the 8 directions, call recursion on that point for finding next letter
            ans = hasPath(board, numRows, numCols, newRowStart, newColStart, visited, patternIndex + 1);
            if (ans)
                break;
            // because if on any iteration a suitable match was found, ans might become false again after other iterations
        }
    }
    // make the cell false again to use later in another pattern search
    visited[rowStart][colStart] = false;
    return ans;
}

// called by main
bool hasPath(vector<vector<char>> &board, int numRows, int numCols)
{
    bool **visited = new bool *[numRows];
    for (int i = 0; i < numRows; i++)
    {
        visited[i] = new bool[numCols];
        for (int j = 0; j < numCols; j++)
        {
            visited[i][j] = false;
        }
    }
    bool possibleAns;
    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < numCols; c++)
        {
            if (board[r][c] == 'C')
            {
                possibleAns = hasPath(board, numRows, numCols, r, c, visited, 1);
                if (possibleAns)
                    return possibleAns;
            }
        }
    }
    return possibleAns;
}
