#include <iostream>
#include <climits>
using namespace std;
void findLargest(int **input, int m, int n)
{
    int colLargest = INT_MIN;
    int rowLargest = INT_MIN;
    int colSum = 0;
    int rowSum = 0;
    int colIndex = 0;
    int rowIndex = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            colSum += input[j][i];
        }
        if (colSum > colLargest)
        {
            colLargest = colSum;
            colIndex = i;
        }
        colSum = 0;
    }

    for (int k = 0; k < m; k++)
    {
        for (int l = 0; l < n; l++)
        {
            rowSum += input[k][l];
        }
        if (rowSum > rowLargest)
        {
            rowLargest = rowSum;
            rowIndex = k;
        }
        rowSum = 0;
    }

    if (rowLargest >= colLargest)
    {
        cout << "row" << ' ' << rowIndex << ' ' << rowLargest;
    }
    else
    {
        cout << "column" << ' ' << colIndex << ' ' << colLargest;
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

        findLargest(input, row, col);
        cout << endl;
    }
}