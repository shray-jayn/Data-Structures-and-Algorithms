#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool detect(int src, vector<int> adj[], int vis[])
{
    vis[src] = 1;
    queue<pair<int, int>> q;

    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        for (auto ajdNode : adj[node])
        {
            if (!vis[ajdNode])
            {
                vis[ajdNode] = 1;
                q.push({ajdNode, node});
            }

            else if (parent != ajdNode) // when parent node is visited and its an adj node it doesnot form a cycle
            {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (detect(i, adj, vis) == true)
            {
                return true;
            }
        }
    }

    return false;
}
