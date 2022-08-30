#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class node
{
public:
    int u;
    int v;
    int wt;

    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool static comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(vector<int> &parent, int node)
{
    if (node == parent[node])
    {
        return node;
    }

    return parent[node] = findPar(parent, parent[node]);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(parent, u);
    v = findPar(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }

    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }

    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes)
{
    // Write your code here.

    // create edges

    vector<node> edges;

    // edges for wells

    for (int i = 0; i < n; i++)
    {
        edges.push_back(node(0, i + 1, wells[i]));
    }

    // egdes for pipes

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            edges.push_back(node(pipes[i][0], pipes[i][1], pipes[i][2]));
        }
    }

    // sort the edges

    sort(edges.begin(), edges.end(), comp);

    // parent and rank array

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }

    vector<pair<int, int>> mst; // for including edges in mst

    int cost = 0;

    for (auto it : edges)
    {
        if (findPar(parent, it.v) != findPar(parent, it.u))
        {
            cost += it.wt;                    // calculating cost
            mst.push_back({it.u, it.v});      // inserting edges in mst
            unionn(it.u, it.v, parent, rank); // to connect we use union operation
        }
    }
    return cost;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> well(n);

        for (int i = 0; i < n; i++)
        {
            cin >> well[i];
        }

        vector<vector<int>> pipes(k, vector<int>(3));

        for (int i = 0; i < k; i++)
        {
            vector<int> val(3);

            for (int j = 0; j < 3; j++)
            {
                cin >> val[j];
            }
            pipes[i] = val;
        }

        cout << supplyWater(n, k, well, pipes) << endl;
    }

    return 0;
}