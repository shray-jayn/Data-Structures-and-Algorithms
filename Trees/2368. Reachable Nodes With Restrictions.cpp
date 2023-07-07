#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(int node, unordered_set<int> &restricted, vector<int> &visited, vector<vector<int>> &adj, int &count)
{
    visited[node] = 1;

    count++;

    for (auto it : adj[node])
    {
        if (visited[it] == 0 and restricted.find(it) == restricted.end())
        {
            dfs(it, restricted, visited, adj, count);
        }
    }
}

int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
{
    int m = edges.size();

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    unordered_set<int> st;

    for (int i = 0; i < restricted.size(); i++)
    {
        st.insert(restricted[i]);
    }

    vector<int> visited(n, 0);

    int count = 0;

    dfs(0, st, visited, adj, count);

    return count;
}

int main()
{

    return 0;
}