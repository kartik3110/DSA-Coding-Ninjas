#include <bits/stdc++.h>
using namespace std;

// this functon only prints BFS of one component. for disconnected graphs, call this on every component.
void printBFS(int **edges, int v, int startingVertex, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(startingVertex);
    visited[startingVertex] = true;
    while (!pendingVertices.empty())
    {
        int front = pendingVertices.front();
        pendingVertices.pop();
        cout << front << " ";
        for (int i = 0; i < v; i++)
        {
            if (edges[front][i] && i != front && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void printEveryComponent(int **edges, int v, bool *visited)
{
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, v, i, visited);
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