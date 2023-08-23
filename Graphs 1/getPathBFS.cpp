#include <bits/stdc++.h>
using namespace std;

// using BFS
unordered_map<int, int> whoInserted;

vector<int> getPath(int **edges, int v, int start, int end, bool *visited)
{
    queue<int> vertices;
    vertices.push(start);
    visited[start] = true;
    while (!vertices.empty())
    {
        int front = vertices.front();
        vertices.pop();

        if (front == end)
        {
            vector<int> vec;
            vec.push_back(front);
            while (whoInserted.count(front) > 0)
            {
                vec.push_back(whoInserted[front]);
                front = whoInserted[front];
            }
            return vec;
        }

        int i;
        for (i = 0; i < v; i++)
        {
            if (edges[front][i] == 1 && !visited[i])
            {
                vertices.push(i);
                whoInserted[i] = front;
                visited[i] = true;
            }

            // to prevent TLE
            if (i == end)
                break;
        }
    }
    // not found
    vector<int> ans;
    return ans;
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
    int source, destination;
    cin >> source >> destination;
    vector<int> ans = getPath(edges, v, source, destination, visited);
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans.at(i) << " ";
        }
    }
}