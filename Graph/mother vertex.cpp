#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int count = 0;

void dfs(vector<vector<int>> &graph, unordered_map<int, bool> &isVisited, int cur, stack<int> st)
{
    isVisited[cur] = true;

    for (auto neighbour : graph[cur])
    {
        if (isVisited[neighbour] == false)
        {
            dfs(graph, isVisited, neighbour, st);
        }
    }

    st.push(cur);
}

void dfs2(vector<vector<int>> &graph, unordered_map<int, bool> &isVisited, int cur)
{
    isVisited[cur] = true;

    count++;

    for (auto neighbour : graph[cur])
    {
        if (isVisited[neighbour] == false)
        {
            dfs2(graph, isVisited, neighbour);
        }
    }

    st.push(cur);
}

int findMotherVertex(int n, vector<vector<int>> graph)
{
    stack<int> st;

    unordered_map<int, bool> isVisited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (isVisited[i] == 0)
        {
            dfs(graph, isVisited, i, stack);
        }
    }

    int ans = st.top();
    st.pop();

    count = 0;

    dfs2(graph, isVisited, ans);

    if (count == n)
    {
        return ans;
    }

    return -1;
}

int main()
{

    return 0;
}