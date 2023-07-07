#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findParent(int node, vector<int> &parent)
{
    while (parent[node] != node)
    {
        node = parent[node];
    }
    return node;
}

void Union(int u, int v, vector<int> &parent, int count)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u != v)
    {
        parent[u] = v;
        count--;
    }
}

bool isValid(vector<int> &pos1, vector<int> &pos2)
{
    if (pos1[0] == pos2[0])
    {
        return true;
    }
    if (pos1[1] == pos2[1])
    {
        return true;
    }
    return false;
}

int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();

    vector<int> parent(n);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = n;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isValid(stones[i], stones[j]))
            {
                Union(i, j, parent, count);
            }
        }
    }

    return (n - count);
}

int main()
{

    return 0;
}