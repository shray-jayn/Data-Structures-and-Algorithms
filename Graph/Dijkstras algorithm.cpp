#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n, m, source;

    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];

    int a, b, wt;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;

        g[a].push_back(make_pair(b, wt));
        g[b].push_back(make_pair(a, wt));
    }

    cin >> source;

    // Dijkstras algo begins from here

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap  , in pair (dist , from)

    vector<int> distTo(n + 1, INT_MAX); // distance array initialised to infinity

    distTo[source] = 0;

    pq.push(make_pair(0, source)); // (dist , src)

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;

        pq.pop();

        vector<pair<int, int>>::iterator it;

        // looking for all the neighbour elements ;
        for (auto it : g[prev])
        {
            int next = it.first;
            int nextDist = it.second;

            if (distTo[next] > dist + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    cout << "The distance from source is " << source << " , are  : " << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << distTo[i] << " ";
    }
    cout << endl;

    return 0;
}