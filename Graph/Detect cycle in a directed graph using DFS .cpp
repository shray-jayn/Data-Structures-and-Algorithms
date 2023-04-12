#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[])
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, vis, pathVis, adj) == true)
            {
                return true;
            }
        }

        else if (pathVis[it])
        {
            return true;
        }
    }

    pathVis[node] = 0; // backtrack
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, pathVis, adj) == true)
            {
                return true;
            }
        }
    }
}

int main()
{

    return 0;
}