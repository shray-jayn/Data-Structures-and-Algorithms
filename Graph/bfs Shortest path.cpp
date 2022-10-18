#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> adjList;

public:
    Graph()
    {
    }

    void addEdge(T u, T v, bool bidir = true)
    {
        adjList[u].push_back(v);

        if (bidir == true)
        {
            adjList[v].push_back(u);
        }
    }

    void print()
    {
        // iterate over the map

        for (auto i : adjList)
        {
            cout << i.first << "-> ";

            // i.second = linkedlist

            for (auto entry : i.second)
            {
                cout << entry << " ,";
            }

            cout << endl;
        }w
    }

    void bfs(T src)
    {
        queue<T> q;

        map<T, bool> visited;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T node = q.front();

            cout << node << " ";

            q.pop();

            // For the neighbours of the current node , find out the nodes which are not visited

            for (int neighbour : adjList[node])
            {
                if (!visited[neighbour] == true)
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void bfsShortest(T src)
    {
        queue<T> q;

        unordered_map<T, T> parent;
        unordered_map<T, int> dist;
        unordered_map<T, bool> isVisited;

        q.push(src);

        parent[src] = src;
        dist[src] = 0;
        isVisited[src] = true;

        while (!q.empty())
        {
            T curr_ele = q.front();
            q.pop();

            cout << curr_ele << " ";

            for (auto it : adjList[curr_ele])
            {
                if (isVisited[it] == false)
                {
                    q.push(it);
                    parent[it] = curr_ele;
                    dist[it] = dist[parent[it]] + 1;
                    isVisited[it] = true;
                }
            }

            for (auto it : adjList)
            {
                T node = it.first;
                cout << "Distance of " << node << " from " << src << " is " << dist[node] << endl;
            }
        }
    }
};

int main()
{

    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 4);

    g.bfsShortest(0);
}
