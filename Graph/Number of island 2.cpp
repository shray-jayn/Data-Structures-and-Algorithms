#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

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

    vector<vector<int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    int count = 0;

    for (int i = 0; i < position.size(); i++)
    {
        int row = position[i][0];
        int col = position[i][1];

        int cellNum = row * n + col;


        if (parent[cellNum] != -1)   // check id the cell is already processed or not 
        {
            ans.push_back(count);
            continue;
        }  

        // not processed so process it 

        parent[cellNum] = cellNum;
        rank[cellNum] = 1;
        count++;

        for (int i = 0; i < 4; i++)
        {
            int rowDir = row + dir[i][0];
            int colDir = col + dir[i][1];

            int cellDir = rowDir * n + colDir;

            if (rowDir < 0 or colDir < 0 or rowDir >= m or colDir >= n or parent[cellDir] == -1)
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

int main()
{

    return 0;
}