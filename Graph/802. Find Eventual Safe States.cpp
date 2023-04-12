#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Using DFS

bool dfsCheck(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis, vector<int> &check)
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : graph[node])
    {
        if (!vis[node])
        {
            if (dfsCheck(it, graph, vis, pathVis, check) == true)
            {
                return true;
            }
        }
        else if (pathVis[it])
        {
            return true;
        }
    }

    check[node] = 1;
    pathVis[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();

    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V, 0);

    vector<int> safeNodes;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfsCheck(i, graph, vis, pathVis, check);
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (check[i] == 1)
        {
            safeNodes.push_back(i);
        }
    }
    return safeNodes;
}


bool dfs(int node, vector<int> &vis, vector<int> &pathvis, vector<int> adj[], vector<int> &check)
{
    vis[node] = 1;
    pathvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, vis, pathvis, adj, check) == true)
                return true;
        }
        else if (pathvis[it])
        {
            return true;
        }
    }
    pathvis[node] = 0;
    check[node] = 1;
    return false;
}


vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    int m = graph[0].size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            adj[i].push_back(graph[i][j]);
        }
    }

    vector<int> vis(n, 0);
    vector<int> pathvis(n, 0);
    vector<int> check(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, pathvis, adj, check);
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (check[i])
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// Using Topological Sort

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
}