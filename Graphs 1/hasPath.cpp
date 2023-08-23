#include <bits/stdc++.h>
using namespace std;

// using DFS
bool hasPath(int **edges, int v, bool *visited, int v1, int v2)
{
    visited[v1] = true;
    if (v1 == v2)
        return true;
    for (int i = 0; i < v; i++)
    {
        if (edges[v1][i] == 1 && !visited[i])
        {
            if (i == v2)
                return true;
            if (hasPath(edges, v, visited, i, v2))
                return true;
        }
    }
    return false;
}

int main()
{
    int v; // total vertices
    int e; // total edges
    cin >> v >> e;
    int **edges = new int *[v]; // adjacency matrix
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;
        edges[firstVertex][secondVertex] = 1;
        edges[secondVertex][firstVertex] = 1;
    }

    bool *visited = new bool[v];
    int v1, v2;
    cin >> v1 >> v2;
    if (hasPath(edges, v, visited, v1, v2))
    {
        cout << "true";
    }
    else
        cout << "false";
}