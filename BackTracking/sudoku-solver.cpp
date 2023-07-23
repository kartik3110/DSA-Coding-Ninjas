#include <bits/stdc++.h>
using namespace std;
#define N 9

bool findEmptyCell(int **sudoku, int &r, int &c)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (sudoku[i][j] == 0)
            {
                r = i;
                c = j;
                return true;
            }
        }
    }
    // no empty cell found
    return false;
}
bool isPossible(int r, int c, int val, int **sudoku)
{
    for (int i = 0; i < N; i++)
    {
        if (sudoku[r][i] == val)
            return false;
    }
    for (int i = 0; i < N; i++)
    {
        if (sudoku[i][c] == val)
            return false;
    }
    int rowFactor = (r / 3) * 3;
    int colFactor = (c / 3) * 3;
    for (int i = rowFactor; i < rowFactor + 3; i++)
    {
        for (int j = colFactor; j < colFactor + 3; j++)
        {
            if (sudoku[i][j] == val)
                return false;
        }
    }
    return true;
}
bool solve(int **sudoku)
{
    int r;
    int c;
    if (!findEmptyCell(sudoku, r, c))
    {
        return true;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (isPossible(r, c, i, sudoku))
        {
            sudoku[r][c] = i;
            if (solve(sudoku))
            {
                return true;
            }
            sudoku[r][c] = 0;
        }
    }
    return false;
}

int main()
{
    int **sudoku = new int *[N];
    for (int i = 0; i < N; i++)
        sudoku[i] = new int[N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> sudoku[i][j]; // 0 if place is empty
    }
    solve(sudoku);
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << sudoku[i][j] << " ";
        cout << endl;
    }

    return 0;
}

// 9 0 0 0 2 0 7 5 0
// 6 0 0 0 5 0 0 4 0
// 0 2 0 4 0 0 0 1 0
// 2 0 8 0 0 0 0 0 0
// 0 7 0 5 0 9 0 6 0
// 0 0 0 0 0 0 4 0 1
// 0 1 0 0 0 5 0 8 0
// 0 9 0 0 7 0 0 0 4
// 0 8 2 0 4 0 0 0 6