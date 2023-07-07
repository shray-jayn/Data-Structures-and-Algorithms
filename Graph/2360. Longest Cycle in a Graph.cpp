#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{

    void dfs(int node, vector<int> &visit, stack<int> &s, vector<int> adj[])
    {
        visit[node] = 1;
        for (auto it : adj[node])
        {
            if (!visit[it])
            {
                dfs(it, visit, s, adj);
            }
        }
        s.push(node);
    }

    void dfs2(int node, vector<int> &visit2, vector<int> &v, vector<int> rev_adj[])
    {
        visit2[node] = 1;
        for (auto it : rev_adj[node])
        {
            if (!visit2[it])
            {
                dfs2(it, visit2, v, rev_adj);
            }
        }
        v.push_back(node);
    }

public:
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        // step1
        stack<int> s;
        vector<int> visit(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                dfs(i, visit, s, adj);
            }
        }
        // reverse
        // step2
        vector<int> rev_adj[n];
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                rev_adj[it].push_back(i);
            }
        }

        // step3
        // vector<vector<int>>ans;
        int ans = INT_MIN;
        vector<int> visit2(n, 0);
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (visit2[node])
                continue;
            vector<int> v;
            dfs2(node, visit2, v, rev_adj);
            int size = v.size();
            ans = max(ans, size);
        }
        return (ans == 1) ? -1 : ans;
    }
};

int main()
{

    return 0;
}