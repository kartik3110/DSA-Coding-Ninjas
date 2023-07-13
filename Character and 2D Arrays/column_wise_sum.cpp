#include <iostream>
using namespace std;
int main()
{
    int arr[100][100]; // using[1000][1000] causing problems.
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int k = 0; k < n; k++)
    {
        int sum = 0;
        for (int l = 0; l < m; l++)
        {
            sum = sum + arr[l][k];
        }
        cout << sum << ' ';
    }

    return 0;
}
