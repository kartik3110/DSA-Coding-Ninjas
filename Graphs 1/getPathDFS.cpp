#include <bits/stdc++.h>
using namespace std;

// using DFS
vector<int> *getPath(int **edges, int v, int start, int end, bool *visited)
{
    // if end vertex is found, add it to the ans vector and return it
    visited[start] = true;
    if (start == end)
    {
        vector<int> *v = new vector<int>({end});
        return v;
    }
    for (int i = 0; i < v; i++)
    {
        if (edges[start][i] && !visited[i])
        {
            vector<int> *smallAns = getPath(edges, v, i, end, visited);
            // if a path from i was found, add start to the path and return the path
            if (smallAns)
            {
                smallAns->push_back(start);
                return smallAns;
            }
        }
    }
    // no path was found. return NULL
    return NULL;
    // other option was to return empty vector and later check if size>0
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
    int start, end;
    cin >> start >> end;
    vector<int> *ans = getPath(edges, v, start, end, visited);
    if (ans)
    {
        for (int i = 0; i < ans->size(); i++)
        {
            cout << ans->at(i) << " ";
        }
    }
}