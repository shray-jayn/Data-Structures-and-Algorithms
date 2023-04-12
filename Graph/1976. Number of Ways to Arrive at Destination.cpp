#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < n; i++)
    {
        int src = roads[i][0];
        int dst = roads[i][1];
        int time = roads[i][2];

        graph[src].push_back({dst, time});
        graph[dst].push_back({src, time});
    }

    vector<int> times(n, 0);

    times[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // max heap

    pq.push({0, 0}); //  <prob,node>

    int count = 0;

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int prevNode = curr.second;
        int prevTime = curr.first;

        for (auto it : graph[prevNode])
        {
            int nextNode = it.first;
            int nextTime = it.second;

            if (prevTime + nextTime < times[nextNode])
            {
                if (nextNode == n - 1)
                {
                    count++;
                }

                times[nextNode] = prevTime + nextTime;
                pq.push({times[nextNode], nextNode});
            }
        }
    }

    return count;
}

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<vector<pair<int, int>>> graph(n);

    int m = roads.size();

    for (int i = 0; i < m; i++)
    {
        int src = roads[i][0];
        int dst = roads[i][1];
        int time = roads[i][2];

        graph[src].push_back({dst, time});
        graph[dst].push_back({src, time});
    }

    vector<int> times(n, INT_MAX);
    vector<int> paths(n, 0);

    times[0] = 0;
    paths[0] = 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0}); //<time,node>

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int prevTime = curr.first;
        int prevNode = curr.second;

        for (auto it : graph[prevNode])
        {
            int nexNode = it.first;
            int nexTime = it.second;

            if (times[nexNode] > prevTime + nexTime)
            {
                times[nexNode] = prevTime + nexTime;
                pq.push({times[nexNode], nexNode});

                paths[nexNode] = paths[prevNode]; // when we find a shorter time we change dp by new value.
            }
            else if (times[nexNode] == prevTime + nexTime)
            {
                paths[nexNode] = paths[nexNode] + paths[prevNode]; // when we find equal time we add value to current node's dp.
            }
        }
    }

    return paths[n - 1];
}

int main()
{

    return 0;
}