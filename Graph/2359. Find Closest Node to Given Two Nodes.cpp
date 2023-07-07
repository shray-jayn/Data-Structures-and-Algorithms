#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(int node, int prevDist, vector<int> &visited, vector<int> adj[], vector<int> &dist)
{
    visited[node] = 1;

    vector<int> neigh = adj[node];

    for (int i = 0; i < neigh.size(); i++)
    {
        if (visited[neigh[i]] == 0)
        {
            dist[neigh[i]] = prevDist + 1;

            dfs(neigh[i], prevDist + 1, visited, adj, dist);
        }
    }
}

int closestMeetingNode(vector<int> &edges, int node1, int node2)
{
    int n = edges.size();

    vector<int> adj[n];

    for (int i = 0; i < n; i++)
    {
        if (edges[i] != -1)
        {
            adj[i].push_back(edges[i]);
        }
    }

    vector<int> visited1(n, 0), visited2(n, 0);

    vector<int> dist1(n, -1), dist2(n, -1);

    dist1[node1] = 0;
    dist2[node2] = 0;

    dfs(node1, 0, visited1, adj, dist1);
    dfs(node2, 0, visited2, adj, dist2);

        for (int i = 0; i < n; i++)
    {
        cout << dist1[i] << " " << dist2[i] << endl;
    }

    int res = -1;
    int min_dist = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        // check if current node is the closest meeting point
        if (min(dist1[i], dist2[i]) >= 0 && max(dist1[i], dist2[i]) < min_dist)
        {
            min_dist = max(dist1[i], dist2[i]);
            res = i;
        }
    }
    return res;
}

int main()
{
    vector<int> edges = {1, 2, -1};
    int node1 = 0;
    int node2 = 2;

    cout << closestMeetingNode(edges, node1, node2) << endl;

    return 0;
}