#include <iostream>
using namespace std;

void wavePrint(int **input, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                cout << input[j][i] << ' ';
            }
        }
        else
        {
            for (int k = m - 1; k >= 0; k--)
            {
                cout << input[k][i] << ' ';
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;
        int **input = new int *[row];
        for (int i = 0; i < row; i++)
        {
            input[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> input[i][j];
            }
        }
        wavePrint(input, row, col);
        cout << endl;
    }
}