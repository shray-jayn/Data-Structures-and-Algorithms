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
    int m = flights.size();

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];

            graph[to].push_back({to, price});
        }
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // initialize the distance vector
    for (int i = 0; i < m; i++)
    {
        int from = flights[i][0];
        int to = flights[i][1];
        int price = flights[i][2];

        if (from == src)
        {
            dist[to] = price;
        }
    }

    // create a priority queue(Min heap)

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // push root into pq; <dist,node>

    pq.push({0, src});

    int stops = 0;
    int ans = INT_MAX;

    while (!pq.empty() and stops <= k)
    {
        int prevPrice = pq.top().first;
        int prev = pq.top().second;

        pq.pop();

        for (auto it : graph[prev])
        {
            int next = it.first;
            int nextPrice = it.second;

            if (dist[next] > prevPrice + nextPrice)
            {
                dist[next] = prevPrice + nextPrice;
                pq.push({dist[next], next});
            }

            if (next == dst)
            {
                ans = min(ans, dist[next]);
            }
        }

        stops++;
    }

    if (ans == INT_MAX)
        return -1;

    return ans;
}

int main()
{

    return 0;
}