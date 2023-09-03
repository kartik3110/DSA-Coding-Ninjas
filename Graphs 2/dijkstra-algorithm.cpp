#include <bits/stdc++.h>
using namespace std;

int findMinimumUnvisitedVertex(int *vertexDistance, bool *visited, int v)
{
    int minValue = 1e9;
    int minIndex;
    for (int i = 0; i < v; i++)
    {
        if (vertexDistance[i] < minValue && !visited[i])
        {
            minValue = vertexDistance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstras(int **edges, int v, int e)
{
    bool *visited = new bool[v];
    int *vertexDistance = new int[v];
    for (int i = 0; i < v; i++)
    {
        vertexDistance[i] = INT_MAX;
    }
    vertexDistance[0] = 0;

    for (int k = 0; k < v; k++)
    {
        int u = findMinimumUnvisitedVertex(vertexDistance, visited, v);
        for (int i = 0; i < v; i++)
        {
            if (edges[u][i] && !visited[i] && (vertexDistance[u] + edges[u][i] < vertexDistance[i]))
            {
                vertexDistance[i] = vertexDistance[u] + edges[u][i];
            }
        }
    }
    // print all shortest Distances
    for (int i = 0; i < v; i++)
    {
        cout << i << " " << vertexDistance[i] << endl;
    }
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
        int u, v, w;
        cin >> u >> v >> w;
        edges[u][v] = w;
    }
    // print shortest distances of all vertices from 0 vertex
    dijkstras(edges, v, e);
}

/* // array of vectors of pairs(adjacency list for weighted graph)
int N = 1e5;
// 1e5 default size is double. so need to typecast it first in int N
vector<pair<int, int>> list[N]; */