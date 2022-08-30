#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findPar(int u, vector<int> &parent)
{
    if (parent[u] == u)
    {
        return u;
    }

    return parent[u] = findPar(parent[u], parent);
}

bool unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);

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

        return false; // no cycle is found
    }

    return true; // cycle is found
}

vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
{
    int n = edges.size();

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 1);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    vector<int> indegree(n + 1, 0);

    int bl1 = -1;
    int bl2 = -1;

    for (int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        if (indegree[v] == -1)
        {
            indegree[v] = i;
        }

        else // check if already an indegree is present so if found means this can be a cycle point and blacklist them
        {
            bl1 = i;
            bl2 = indegree[v];

            break;
        }
    }

    // DSU

    for (int i = 0; i < n; i++)
    {
        if (i == bl1) // cycle is present if bl1 == -1 means no cycle is present
        {
            continue;
        }
        int u = edges[i][0];
        int v = edges[i][1];

        bool flag = unionn(u, v, parent, rank);

        if (flag == true) // cycle is present
        {
            if (bl1 == -1)
            {
                return edges[i]; // CASE 2 HAI YEH jab sirf cycle hogi but koi 2 parent nhi hoge
            }

            else
            {
                return edges[bl2]; // CASE 3  jab cycle or 2 parent present hoge
            }
        }
    }

    return edges[bl1]; // CASE 1 jab humne sahi bande ko black list kia  or 2 parent present the
}

int find(int u, vector<int> &parent)
{
    if (parent[u] < 0)
        return u;

    parent[u] = find(parent[u], parent);
    return parent[u];
}

bool union_by_weight(int u, int v, vector<int> &parent)
{
    int pu = find(u, parent);
    int pv = find(v, parent);

    if (pu == pv)
        return 0;

    if (parent[pu] < parent[pv])
    {
        parent[pu] += parent[pv];
        parent[pv] = pu;
    }
    else
    {
        parent[pv] += parent[pu];
        parent[pu] = pv;
    }
    return 1;
}

vector<int> findRedundantDirectedConnection(vector<vector<int>> &e)
{

    int i, n = e.size();

    vector<int> parent(n + 1, -1);
    vector<int> in(n + 1, -1);

    int e1 = -1, e2 = -1;

    for (i = 0; i < n; i++)
    {
        if (in[e[i][1]] != -1) // indegree 2
        {
            e2 = in[e[i][1]]; // first edge causing indegree 2
            e1 = i;           // second edge causing indegree 2
            break;
        }
        in[e[i][1]] = i;
    }

    for (i = 0; i < n; i++)
    {
        if (i == e1) // ignore edge causing indegree
            continue;

        if (!union_by_weight(e[i][0], e[i][1], parent)) // cycle is present
        {
            if (e1 != -1) // indegree 2 , wrong edge ignored
                return e[e2];
            else // indegree 1 , remove edge causing cycle
                return e[i];
        }
    }
    return e[e1];
}

int main()
{

    return 0;
}