#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Bfs topological sort  (Kahn's Algorithm)

void topologicalSortBfs(map<int, list<int>> &adjList)
{
    queue<int> q;

    unordered_map<int, int> indegree;
    unordered_map<int, bool> isVisited;

    // set indegree of all nodes as 0 and mark as not visited

    for (auto it : adjList)
    {
        indegree[it.first] = 0;
        isVisited[it.first] = false;
    }

    // calculate indegree of each node

    for (auto it : adjList)
    {
        int node = it.first;

        for (auto itr : adjList[node])
        {
            indegree[itr]++;
        }
    }

    // find node with 0 indegree

    for (auto it : indegree)
    {
        if (it.second == 0)
        {
            q.push(it.first);
        }
    }

    while (!q.empty())
    {
        auto curNode = q.front();
        q.pop();

        for (auto it : adjList[curNode])
        {
            indegree[it]--;

            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
}

// bfs topological sort

// 01 Matrix

void bfs(vector<vector<int>> &grid, vector<vector<int>> &dis)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                q.push({i, j});
                dis[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {

        auto point = q.front();
        q.pop();

        int x = point.first;
        int y = point.second;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 or nx >= grid.size() or ny < 0 or ny >= grid[nx].size() or grid[nx][ny] == 0 or dis[nx][ny] != -1)
                continue;
            q.push({nx, ny});
            dis[nx][ny] = dis[x][y] + 1;
        }
    }
}
vector<vector<int>> updateMatrix(vector<vector<int>> &grid)
{
    vector<vector<int>> dis(grid.size(), vector<int>(grid[0].size(), -1));
    bfs(grid, dis);
    return dis;
}

// Sliding puzzle

int slidingPuzzle(vector<vector<int>> &board)
{
    int n = 2, m = 3;

    string s = "";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            s += to_string(board[i][j]);
        }
    }

    string target = "123450";

    vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

    unordered_map<string, bool> isVisited;

    if (s == target)
    {
        return 0;
    }

    queue<string> q;
    q.push(s);

    int level = 0;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            string temp = q.front();
            q.pop();

            if (temp == target)
                return level;

            int idx = -1;

            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] == '0')
                {
                    idx = i;
                    break;
                }
            }

            vector<int> array = dir[idx];

            for (int i = 0; i < array.size(); i++)
            {
                string news = temp;

                swap(news[idx], news[array[i]]);

                if (isVisited.find(news) != isVisited.end())
                    continue;

                isVisited[news] = true;

                q.push(news);
            }
        }

        level++;
    }

    return -1;
}

// Min swaps to sort the array

int minSwaps(vector<int> &nums)
{
    int n = nums.size();

    vector<pair<int, int>> pairArr;

    for (int i = 0; i < n; i++)
    {
        pairArr.push_back({nums[i], i});
    }

    sort(pairArr.begin(), pairArr.end());

    // create a network

    int swaps = 0;

    vector<int> isVisited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (pairArr[i].second == i or isVisited[i] == 1) // element in correct position
        {
            continue;
        }

        int cycleLen = 0;

        int j = i;

        while (isVisited[j] != true)
        {
            isVisited[j] = true;
            cycleLen++;

            j = pairArr[j].second;
        }

        swaps += (cycleLen - 1);
    }

    return swaps;
}

// Dijkstra's Algortithm

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dis(V, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min Heap

    dis[S] = 0;

    pq.push({0, S});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        int node = cur.first;
        int dist = cur.second;

        // check neighbours

        for (vector<int> v : adj[node])
        {
            if (dist + v[1] < dis[v[0]])
            {
                dis[v[0]] = dist + v[1];
                pq.push({dist + v[1], v[0]});
            }
            // otherwise if the distance is greater than the already contained distance in 'dis' vector
            // then we'll do nothing
        }
    }

    return dis;
}

// dsu

int parent[100];
int size[100];

void make(int v)
{
    parent[v] = v;
}

int find(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    // path compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        parent[b] = a;

        size[a] += size[b];
    }
}

// krushkals Algo. For Minimum spanning Tree

int findParent(int u, vector<int> &parent)
{
}

void Union_(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }

    if (rank[v] > rank[v])
    {
        parent[u] = v;
    }

    else // both have same ranks
    {
        parent[u] = v;
        rank[u]++;
    }
}

struct Node
{
    int u;
    int v;
    int wt;

    Node(int first, int second, int weight)
    {
        this->u = first;
        this->u = second;
        this->wt = weight;
    }
};

bool comp()
{
    return true;
}

int costOfMST(vector<Node> &nodes) // <U,V,Wt.>
{
    int n = nodes.size();

    sort(nodes.begin(), nodes.end(), comp);

    // make parent ;

    vector<int> parent;

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    // set intial rank = 0
    vector<int> rank(n, 0);

    int cost = 0;

    for (auto it : nodes)
    {
        int u = it.u;
        int v = it.v;
        int wt = it.wt;
    }
}

// Kosa raju Algo.

void dfs(int node, vector<int> st, vector<int> isVisited, vector<int> adj[])
{
    isVisited[node] = 1;

    for (auto it : adj[node])
    {
        dfs(it, st, isVisited, adj);
    }

    st.push_back(node);
}

void topologicalSort(vector<int> adj[])
{
    int n = adj[0].size();

    vector<int> isVisited(n, 0);

    stack<int> st;

    // topological sort

    for (int i = 1; i <= n; i++)
    {
        if (isVisited[i] != 1)
        {
            // dfs(i, st, isVisited, adj);
        }
    }

    // transpose graph (reverse directions )

    for (int i = 1; i <= n; i++)
    {
        isVisited[i] = 0;

        for (auto it : adj[i])
        {
        }
    }
}

int main()
{
    int n, m;

    vector<int> adj[n + 1];
}

// Mother Vertex

void dfs1(int &node, vector<vector<int>> &graph, vector<bool> &isVisited, stack<int> &st)
{
    isVisited[node] = 1;

    for (auto it : graph[node])
    {
        if (isVisited[it] == 0)
        {
            dfs1(it, graph, isVisited, st);
        }
    }

    st.push(node);
}

int findMotherVertex(int n, vector<vector<int>> graph)
{
    vector<bool> isVisited(n + 1, 0);

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (isVisited[i] == 0)
        {
            dfs1(i, graph, isVisited, st);
        }
    }

    int ans = st.top();

    int count = 0;

    // use bfs to count nodes ;

    if (count == n)
    {
        return ans;
    }
    return -1;
}

// Number of Island 2

int findparent(int node, vector<int> &parent) // find parent function (fro disjoint set)
{
    if (node == parent[node])
        return node;
    return parent[node] = findparent(parent[node], parent);
}

bool unionn(int u, int v, vector<int> &parent, vector<int> &rank) // Union function
{
    u = findparent(u, parent);
    v = findparent(v, parent);

    if (u != v) // when u and v are not equal return true else return false
    {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
        return true;
    }
    return false;
}

vector<int> numIsland2(int m, int n, vector<vector<int>> position)
{
    vector<int> ans;

    vector<int> parent(m * n, -1);
    vector<int> rank(m * n, 0);

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int count = 0;

    for (int i = 0; i < position.size(); i++)
    {
        int row = position[i][0];
        int col = position[i][1];

        int cellNum = row * n + col;

        if (parent[cellNum] != -1) // already been processed
        {
            ans.push_back(count);
            continue;
        }

        parent[cellNum] = cellNum;
        rank[cellNum] = 1;
        count++;

        for (int j = 0; j < 4; j++)
        {
            int rowDir = row + dir[j][0];
            int colDir = col + dir[j][1];

            int cellDir = rowDir * n + colDir;

            if (rowDir >= n or rowDir < 0 or colDir >= m or colDir < 0 or parent[cellDir] == -1)
            {
                continue;
            }
            
            if (unionn(cellNum, colDir, parent, rank) == true)
            {
                count--;
            }
        }

        ans.push_back(count);
    }

    return ans;
}

// Bellman ford Algo.