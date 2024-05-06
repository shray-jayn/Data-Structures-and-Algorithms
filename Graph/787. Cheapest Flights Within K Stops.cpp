#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// solved using bfs

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> graph(n);

    for (auto e : flights)
    {
        graph[e[0]].push_back({e[1], e[2]});
    }

    int ans = INT_MAX;

    vector<int> dist(n, INT_MAX);

    queue<pair<int, int>> q;
    q.push({src, 0});

    int stops = 0;

    while (stops <= k && !q.empty())
    {
        int sz = q.size();

        while (sz--)
        {
            int cnode = q.front().first;
            int cdist = q.front().second;

            q.pop();

            if (cdist > dist[cnode])
                continue;

            dist[cnode] = cdist;

            for (auto e : graph[cnode])
            {
                if (e.second + cdist > ans)
                    continue;

                if (e.first == dst)
                    ans = min(ans, e.second + cdist);

                q.push({e.first, e.second + cdist});
            }
        }

        stops++;
    }

    if (ans == INT_MAX)
        return -1;

    return ans;
}

// using dijkstra's algorithm

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    queue<pair<int, pair<int, int>>> q; //{stops, nodereached, cost};

    vector<pair<int, int>> adjLs[n];

    vector<int> dis(n, 1e9);

    dis[src] = 0;

    // Creating the adjacency list

    for (auto it : flights)
    {
        adjLs[it[0]].push_back({it[1], it[2]});
    }

    q.push({0, {src, 0}}); // Starting from source

    while (!q.empty())
    {
        auto it1 = q.front();
        q.pop();

        int stops = it1.first;
        int node = it1.second.first;
        int cost = it1.second.second;

        if (stops > k)
        {
            continue;
        }

        for (auto it2 : adjLs[node])
        {
            int nnode = it2.first;
            int ncost = it2.second;

            if (stops <= k && ncost + cost < dis[nnode])
            {
                dis[nnode] = ncost + cost;
                q.push({stops + 1, {nnode, ncost + cost}});
            }
        }
    }

    if (dis[dst] == 1e9)
    {
        return {-1};
    }

    return dis[dst];
}

int main()
{

    return 0;
}