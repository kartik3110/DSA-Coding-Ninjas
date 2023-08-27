#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int start;
    int end;
    int weight;

    void printEdge()
    {
        cout << min(start, end) << " " << max(start, end) << " " << weight << endl;
    }
};

bool compareEdges(Edge &a, Edge &b)
{
    return a.weight < b.weight;
}

// find representative of the group containing x.
int Find(int x, int *parents)
{
    if (parents[x] == x)
        return x;
    return Find(parents[x], parents);
}

// union the groups containing x and y
void Union(int x, int y, int *parents)
{
    parents[Find(x, parents)] = Find(y, parents);
}

Edge *kruskals(Edge *graphEdges, int v, int e)
{
    // sort the graphEdges in increasing weights.
    sort(graphEdges, graphEdges + e, compareEdges);
    Edge *MstEdges = new Edge[v - 1];

    int *parents = new int[v];
    // make v different disjoint sets
    for (int i = 0; i < v; i++)
    {
        parents[i] = i;
    }
    int totalEdges = 0, i = 0;
    while (totalEdges < v - 1)
    {
        int v1 = graphEdges[i].start;
        int v2 = graphEdges[i].end;
        if (parents[v1] != parents[v2]) // they belong to disjoint sets
        {
            Union(v1, v2, parents);
            MstEdges[i] = graphEdges[i];
            totalEdges++;
        }
        i++;
    }
    return MstEdges;
}

int main()
{
    int v, e;
    cin >> v >> e;
    // GraphEdges array contains all the edges in the initial graph
    Edge *graphEdges = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        graphEdges[i].start = s;
        graphEdges[i].end = e;
        graphEdges[i].weight = w;
    }
    Edge *MstEdges = kruskals(graphEdges, v, e);
    for (int i = 0; i < v - 1; i++)
    {
        MstEdges[i].printEdge();
    }
}