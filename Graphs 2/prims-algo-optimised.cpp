// for reference: https://www.youtube.com/watch?v=eB61LXLZVqs
// https://www.youtube.com/watch?v=lg-HC6Q7kEE&pp=ygUUcHJpbSdzIGFsZ29yaXRobSBjKys%3D

/* THIS IS INCOMPLETE CODE. WILL COMPLETE LATER */

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

void printMST(pair<int, int> *parent, int v, vector<pair<int, int>> *list)
{
    for (int i = 0; i < v; i++)
    {
        if (parent[i].first < i)
            cout << parent[i].first << " " << i << " " << parent[i].second << endl; // <----problem lies here
        else
            cout << i << " " << parent[i].first << " " << parent[i].second << endl;
    }
}

void primsAlgo(vector<pair<int, int>> *list, int v, int e = 0)
{
    // iterative algorithm
    int *vertexWeight = new int[v]; // weight on edge of parent to this vertex
    bool *visited = new bool[v];
    pair<int, int> *parent = new pair<int, int>[v]; // to print the mst, we will need the parents(signifying edges)
    for (int i = 0; i < v; i++)
    {
        vertexWeight[i] = INT_MAX;
    }
    vertexWeight[0] = 0;
    parent[0] = make_pair(-1, 0);

    for (int k = 0; k < v; k++)
    {
        // find a starting vertex u
        int u = findMinimumUnvisitedVertex(visited, vertexWeight, v);
        visited[u] = true;
        for (int i = 0; i < list[u].size(); i++) // checking for edge on all vertices. use adjacency list for improved TC
        {
            int secondVertex = list[u][i].first;
            int edgeWeight = list[u][i].second;
            if (!visited[secondVertex] && edgeWeight < vertexWeight[secondVertex])
            {
                vertexWeight[secondVertex] = edgeWeight;
                parent[secondVertex] = {u, edgeWeight}; // edge is created bw u and i
            }
        }
    }
    cout << "vertex" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << vertexWeight[i] << " ";
    }

    printMST(parent, v, list);
}

int main()
{
    int e, v;
    cin >> v >> e;
    vector<pair<int, int>> list[(int)1e5];

    while (e--)
    {
        int s, e, w;
        cin >> s >> e >> w;
        list[s].push_back({e, w}); //{} is used to make a pair like make_pair()
        list[e].push_back({s, w}); //{} is used to make a pair like make_pair()
    }
    primsAlgo(list, v, e);
}

/* Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.

For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note: Order of different edges doesn't matter.
Input Format:
Line 1: Two Integers V and E (separated by space)
Next E lines: Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format:
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
1 <= Wi <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8


Sample Output 1 :
0 1 3
1 2 1
0 3 5

*/
