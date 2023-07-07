#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findParent(int u, vector<int> &parent)
{
    if (parent[u] == u)
    {
        return u;
    }
    return findParent(parent[u], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u != v)
    {
        if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else if (rank[v] > rank[u])
        {
            parent[u] = v;
        }
        else
        {
            parent[u] = v;
            rank[v]++;
        }
    }
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{

    vector<int> parent(n);
    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        if (parent[u] != parent[v])

            Union(u, v, parent, rank);
    }

    if (parent[source] == parent[destination])
    {
        return true;
    }

    return false;
}

int main()
{

    return 0;
}