#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Using DFS

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

        else if (pathvis[it]) // if adj node is visited and it's path is also visited => cycle is detected
        {
            return true;
        }
    }

    pathvis[node] = 0; // backtrack
    check[node] = 1;   // if the dfs is over it means no cycle -> push the node as safe node

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

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<int> adjRev[V];
    int indegree[V] = {0};

    // Reverse the graph -> create new adj list 

    for (int i = 0; i < V; i++)
    {
        // i -> it
        // it -> i

        for (auto it : adj[i])
        {
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    vector<int> safeNodes;

    // initalize indegree of all nodes 

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // apply bfs algorithm 

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
 
        safeNodes.push_back(node);  // push all nodes wuth indegree 0 into safeNodes

        for (auto it : adjRev[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }

    }

    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
}