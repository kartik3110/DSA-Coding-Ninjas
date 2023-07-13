#include <iostream>
using namespace std;

void spiralPrint(int **input, int m, int n)
{
    int rs = 0;
    int cs = 0;
    int ce = n - 1;
    int re = m - 1;
    int count = 0;
    bool isCount = (count < m * n);
    while (count < m * n)
    {
        for (int i = cs; (i <= ce) && (count < m * n); i++)
        {
            cout << input[rs][i] << ' ';
            count++;
        }
        rs++;
        for (int j = rs; (j <= re) && (count < m * n); j++)
        {
            cout << input[j][ce] << ' ';
            count++;
        }
        ce--;
        for (int k = ce; (k >= cs) && (count < m * n); k--)
        {
            cout << input[re][k] << ' ';
            count++;
        }
        re--;
        for (int l = re; (l >= rs) && (count < m * n); l--)
        {
            cout << input[l][cs] << ' ';
            count++;
        }
        cs++;
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
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}