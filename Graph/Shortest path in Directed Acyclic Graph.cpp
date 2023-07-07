#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
private:
    void dfs(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            int v = it.first;

            if (!vis[v])
                dfs(v, adj, vis, st);
        }

        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // Making Adj list for given graph

        vector<pair<int, int>> adj[N];

        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        // Topological sort by using Dfs

        int vis[N] = {0};
        stack<int> st;

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> dist(N, 1e9);
        dist[0] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto i : adj[node])
            {
                int v = i.first;
                int wt = i.second;
                dist[v] = min(dist[v], wt + dist[node]);
            }
        }
        

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

int main()
{

    return 0;
}