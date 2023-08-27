// for reference: https://www.youtube.com/watch?v=eB61LXLZVqs
// https://www.youtube.com/watch?v=lg-HC6Q7kEE&pp=ygUUcHJpbSdzIGFsZ29yaXRobSBjKys%3D
#include <bits/stdc++.h>
using namespace std;

// O(N). use PQ for O(logN)
int findMinimumUnvisitedVertex(bool *visited, int *vertexWeight, int v)
{
    int minIndex = 0;
    int minValue = 1e9;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && vertexWeight[i] < minValue)
        {
            minIndex = i;
            minValue = vertexWeight[i];
        }
    }
    return minIndex;
}

void printMST(int *parent, int v, int **graphEdges)
{
    for (int i = 1; i < v; i++)
    {
        if (parent[i] < i)
            cout << parent[i] << " " << i << " " << graphEdges[parent[i]][i] << endl;
        else
            cout << i << " " << parent[i] << " " << graphEdges[parent[i]][i] << endl;
    }
}

void primsAlgo(int **graphEdges, int v, int e = 0)
{
    // iterative algorithm
    int *vertexWeight = new int[v]; // weight on edge of parent to this vertex
    bool *visited = new bool[v];
    int *parent = new int[v]; // to print the mst, we will need the parents(signigy edges)
    for (int i = 0; i < v; i++)
    {
        vertexWeight[i] = INT_MAX;
    }
    vertexWeight[0] = 0;
    parent[0] = -1;

    for (int k = 0; k < v; k++)
    {
        // find a starting vertex u
        int u = findMinimumUnvisitedVertex(visited, vertexWeight, v);
        visited[u] = true;
        // this for loop will draw one edge from 'u' (minimum edge)
        for (int i = 0; i < v; i++) // checking for edge on all vertices. use adjacency list for improved TC
        {
            if (graphEdges[u][i] && !visited[i] && graphEdges[u][i] < vertexWeight[i])
            {
                vertexWeight[i] = graphEdges[u][i];
                parent[i] = u; // edge is created bw u and i
            }
        }
    }
    printMST(parent, v, graphEdges);
}

int main()
{
    int e, v;
    cin >> v >> e;
    int **graphEdges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        graphEdges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            graphEdges[i][j] = 0;
        }
    }
    while (e--)
    {
        int s, e, w;
        cin >> s >> e >> w;
        graphEdges[s][e] = w;
        graphEdges[e][s] = w;
    }
    primsAlgo(graphEdges, v, e);
}