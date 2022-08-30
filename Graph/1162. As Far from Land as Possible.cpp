#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isValid(int i, int j, vector<vector<int>> &grid)
{
    if ((i < 0 or i > grid.size()-1) or (j < 0 or j > grid[0].size()-1))
    {
        return false;
    }

    return true;
}

int maxDistance(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();

    vector<vector<int>> cell(r, vector<int>(c, -1));
    queue<pair<int, int>> bfs;

    // set the water cells to 0 and land cells to -1
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 1)
            {
                cell[i][j] = 0;
                bfs.push({i, j});
            }
        }
    }

    int dist = 1;
    while (!bfs.empty())
    {
        int len = bfs.size();

        for (int k = 0; k < len; k++)
        {

            // for each cell check its 4 boundary cells
            // if it is not visited, increase its distance from land cell by 1
            pair<int, int> curr = bfs.front();
            bfs.pop();
            int i = curr.first, j = curr.second;

            // top cell
            if (i > 0 && cell[i - 1][j] == -1)
            {
                cell[i - 1][j] = dist;
                bfs.push({i - 1, j});
            }
            // left cell
            if (j > 0 && cell[i][j - 1] == -1)
            {
                cell[i][j - 1] = dist;
                bfs.push({i, j - 1});
            }
            // bottom cell
            if (i < r - 1 && cell[i + 1][j] == -1)
            {
                cell[i + 1][j] = dist;
                bfs.push({i + 1, j});
            }
            // right cell
            if (j < c - 1 && cell[i][j + 1] == -1)
            {
                cell[i][j + 1] = dist;
                bfs.push({i, j + 1});
            }
        }

        // after one complete round increase the distance by 1
        dist += 1;
    }

    // find the maximum distance among the cells
    int m = INT_MIN;
    for (auto v : cell)
    {
        for (int i : v)
        {
            if (i > m)
            {
                m = i;
            }
        }
    }

    // if maximum value is 0,
    // which means the cell with the closest land cell is a land cell
    // return -1
    if (m == 0)
    {
        return -1;
    }

    return m;
}

int main()
{

    return 0;
}