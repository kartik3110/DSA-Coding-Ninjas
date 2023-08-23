#include <bits/stdc++.h>
using namespace std;
vector<int> oneComponent;
void DFS(int **edges, int v, bool *visited, int start = 0)
{
    visited[start] = true;
    oneComponent.push_back(start);
    for (int i = 0; i < v; i++)
    {
        if (edges[start][i] && !visited[i])
        {
            DFS(edges, v, visited, i);
        }
    }
}

vector<vector<int>> getAllComponents(int **edges, int v)
{
    bool *visited = new bool[v];
    vector<vector<int>> ans;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            DFS(edges, v, visited, i);
            sort(oneComponent.begin(), oneComponent.end()); // thats how they want the ans.
            ans.push_back(oneComponent);
            oneComponent.clear();
        }
    }
    return ans;
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
    vector<vector<int>> ans = getAllComponents(edges, v);
    for (auto vec : ans)
    {
        for (auto i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}