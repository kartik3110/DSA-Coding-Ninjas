#include <bits/stdc++.h>
using namespace std;

// for each vertex, find its neighbour. then find its neighbour. then check if the neighbour's neighbour is connected to the first point.
// this causes every cycle to get counted 6 times. so return count/6

int count3cycles(int **edges, int v)
{
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (edges[i][j])
            {
                for (int k = 0; k < v; k++)
                {
                    if (edges[j][k] && k != i)
                    {
                        if (edges[k][i])
                            count++;
                    }
                }
            }
        }
    }
    return count / 6;
}
int main()
{
    // Write your code here
    int v, e;
    cin >> v >> e;
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }
    while (e--)
    {
        int first, second;
        cin >> first >> second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }

    int res = count3cycles(edges, v);
    cout << res;
}