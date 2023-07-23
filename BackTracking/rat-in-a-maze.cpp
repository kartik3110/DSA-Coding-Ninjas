// To get all test cases accepted, make recursive calls in the order: Top, Down, Left, Right.
// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int solution[18][18];

void solve(int **maze, int r, int c)
{
    if (r == n - 1 && c == n - 1)
    {
        // solution has been reached
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solution[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }
    if (r >= n || c >= n || r < 0 || c < 0 || maze[r][c] == 0)
    {
        return;
    }
    solution[r][c] = 1;
    solve(maze, r - 1, c); // will return if contraints are not possible
    solve(maze, r + 1, c);
    solve(maze, r, c - 1);
    solve(maze, r, c + 1);
    // reaching this line means all 4 directions returned
    solution[r][c] = 0;

    return;
}

int main()
{
    memset(solution, 0, 18 * 18 * sizeof(int));
    cin >> n;
    int **maze = new int *[n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    solve(maze, 0, 0);
    return 0;
}
