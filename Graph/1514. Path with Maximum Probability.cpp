#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < n; i++)
    {
        int src = edges[i][0];
        int dst = edges[i][1];

        graph[src].push_back({dst, succProb[src]});
        graph[dst].push_back({src, succProb[dst]});
    }

    vector<double> probabilty(n, 0);

    probabilty[start] = 1;

    priority_queue<pair<double, int>> pq; // max heap

    pq.push({succProb[start], start}); //  <prob,node>

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int prevNode = curr.second;
        double prevProb = curr.first;

        for (auto it : graph[prevNode])
        {
            int nextNode = it.first;
            double nextProb = it.second;

            if (prevProb * nextProb > probabilty[nextNode])
            {
                probabilty[nextNode] = prevProb * nextProb;
                pq.push({probabilty[nextNode], nextNode});
            }
        }
    }

    return probabilty[end];
}

int main()
{

    return 0;
}