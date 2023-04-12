#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Using Dijkstra's Algorithm

int dijkstra(int n, int src, int distanceThreshold, vector<vector<pair<int, int>>> &graph)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap

    pq.push({dist[src], src});

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int prevDist = curr.second;
        int prevNode = curr.first;

        for (auto it : graph[prevNode])
        {
            int nextNode = it.first;
            int nextDist = it.second;

            if (dist[nextNode] > prevDist + nextDist)
            {
                dist[nextNode] = prevDist + nextDist;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    int count = 0;

    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] <= distanceThreshold and i != src)
        {
            count++;
        }
    }

    return count;
}

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < n; i++)
    {
        int src = edges[i][0];
        int dst = edges[i][1];
        int dist = edges[i][2];

        graph[src].push_back({dst, dist});
        graph[dst].push_back({src, dist});
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int count = dijkstra(n, i, distanceThreshold, graph);

        ans = max(ans, count);
    }

    return ans;
}

// Using Floyd Warshall's algorithm

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
}

int main()
{

    return 0;
}