#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findparent(int node, vector<int> &parent) // find parent function (fro disjoint set)
{
    if (node == parent[node])
        return node;
    return parent[node] = findparent(parent[node], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) // Union function
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
    }
}

bool equationsPossible(vector<string> &equations)
{
    vector<int> parent(26);
    vector<int> rank(26, 1);

    for (int i = 0; i < 26; i++)
    {
        parent[i] = i;
    }

    for (auto equation : equations)
    {
        if (equation[1] == '=')
        {
            unionn(equation[0] - 'a', equation[3] - 'a', parent, rank);
        }
    }

    for (auto equation : equations)
    {
        if (equation[1] == '!')
        {
            int lx = findparent(equation[0] - 'a', parent);
            int ly = findparent(equation[3] - 'a', parent);

            if (lx == ly)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}