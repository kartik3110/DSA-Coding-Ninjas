#include <bits/stdc++.h>
using namespace std;

// this functon only prints BFS of one component. for disconnected graphs, call this on every component.
void printDFS(int **edges, int v, int startingVertex, bool *visited)
{
    cout << startingVertex << " ";
    visited[startingVertex] = true;
    for (int i = 0; i < v; i++)
    {
        if (edges[startingVertex][i] && !visited[i])
            printDFS(edges, v, i, visited);
    }
}

void printEveryComponent(int **edges, int v, bool *visited)
{
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, v, i, visited);
        }
    }
}

int main()
{
    // Write your code here
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
    printEveryComponent(edges, v, visited);
}