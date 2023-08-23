#include <bits/stdc++.h>
using namespace std;

void DFStraversal(int **edges, int v, bool *visited, int start = 0)
{
    visited[start] = true;
    for (int i = 0; i < v; i++)
    {
        if (edges[start][i] == 1 && !visited[i])
        {
            DFStraversal(edges, v, visited, i);
        }
    }
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
        int start, end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }
    bool *visited = new bool[v];
    DFStraversal(edges, v, visited);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            cout << "false";
            return 0;
        }
    }
    cout << "true";
}