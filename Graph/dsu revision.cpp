#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node
{
    int u;
    int v;
    int weight;

    Node(int wt, int first, int second)
    {
        this->u = first;
        this->v = second;
        this->weight = wt;
    }
};

bool static comp(Node a, Node b)
{
    return a.weight < b.weight;
}

int findParent(int u, vector<int> &parent)
{
    if (u == parent[u])
    {
        return u;
    }

    return parent[u] = findParent(parent[u], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] == rank[v])
    {
        rank[u]++;
        parent[v] = u;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Node> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back({wt, u, v});
    }

    // sort all the edges acc to wt.

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n);
    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int cost = 0;

    for (auto it : edges)
    {
        if (findParent(it.u, parent) != findParent(it.v, parent))
        {
            cost += it.weight;
            Union(it.u, it.v, parent, rank);
        }
    }

    return 0;
}