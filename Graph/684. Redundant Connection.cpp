#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findPar(int x, vector<int> &parent)
{
    if (parent[x] == x)
    {
        return x;
    }

    return parent[x] = findPar(parent[x], parent);
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size();

    vector<int> parent(n + 1); // 1 based indexing hai

    vector<int> rank(n + 1, 1);

    for (int i = 1; i < n + 1; i++)
    {
        parent[i] = i;
    }

    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1];

        int lu = findPar(u, parent);
        int lv = findPar(v, parent);

        if (lu != lv) // merge them
        {
            if (rank[lu] > rank[lv])
            {
                parent[lv] = lu;
            }

            else if (rank[lu] < rank[lv])
            {
                parent[lu] = lv;
            }

            else // both have same rank
            {
                parent[lu] = lv;
                rank[lv]++;
            }
        }

        else // baoth have same parent  --> cycle wil be formed hence ans
        {
            return edge;
        }
    }

    return vector<int>(2);
}

int main()
{

    return 0;
}