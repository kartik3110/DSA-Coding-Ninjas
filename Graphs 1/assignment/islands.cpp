#include <bits/stdc++.h>
using namespace std;

void DFS(int **edges, int v, int start, bool *visited)
{
    visited[start] = true;
    for (int i = 0; i < v; i++)
    {
        if (edges[start][i] == 1 && !visited[i])
        {
            DFS(edges, v, i, visited);
        }
    }
}

// return number of connected components in a graph
int numComponents(int **edges, int v)
{
    int count = 0;
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            DFS(edges, v, i, visited);
            count++;
        }
    }
    return count;
}

int main()
{
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
    cout << numComponents(edges, v);
}