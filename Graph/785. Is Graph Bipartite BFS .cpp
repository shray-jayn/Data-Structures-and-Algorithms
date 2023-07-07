#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool bfs(int node, vector<int> &color, vector<vector<int>> &graph)
{
    queue<int> q;
    q.push(node);
    color[node] = 1;
    
    while (!q.empty())
    {
        int adjacent = q.front();
        q.pop();

        for (auto it : graph[adjacent])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[adjacent];
                q.push(it);
            }
            else if (color[it] == color[adjacent])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();

    vector<int> colour(n - 1);

    for (int i = 0; i < n; i++)
    {
        if (colour[i] == -1)
        {
            if (!bfs(i, colour, graph))
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}