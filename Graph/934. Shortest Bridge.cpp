#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(int i, int j, vector<vector<int>> &grid, queue<pair<int, int>> &q, vector<vector<int>> &cell)
{

    if (i < 0 or i > grid.size() - 1 or j < 0 or j > grid[0].size() - 1)
    {
        return;
    }

    if (grid[i][j] == 1)
    {
        grid[i][j] = -1;
        cell[i][j] = 0;

        q.push({i, j});

        dfs(i, j + 1, grid, q, cell);
        dfs(i, j - 1, grid, q, cell);
        dfs(i + 1, j, grid, q, cell);
        dfs(i - 1, j, grid, q, cell);
    }
}

int shortestBridge(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();

    bool flag = 0;

    queue<pair<int, int>> bfs;
    vector<vector<int>> cell(r, vector<int>(c, -1));

    for (int i = 0; i < r; i++)
    {
        if (flag == 1)
        {
            break;
        }

        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(i, j, grid, bfs, cell);
                flag = 1;

                break;
            }
        }
    }

    int dist = 1;
    int minDist = INT_MAX;

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
                if (grid[i - 1][j] == 1)
                {
                    minDist = min(minDist, dist);
                }
                bfs.push({i - 1, j});
            }
            // left cell
            if (j > 0 && cell[i][j - 1] == -1)
            {
                cell[i][j - 1] = dist;
                if (grid[i][j - 1] == 1)
                {
                    minDist = min(minDist, dist);
                }
                bfs.push({i, j - 1});
            }
            // bottom cell
            if (i < r - 1 && cell[i + 1][j] == -1)
            {
                cell[i + 1][j] = dist;
                if (grid[i + 1][j] == 1)
                {
                    minDist = min(minDist, dist);
                }
                bfs.push({i + 1, j});
            }
            // right cell
            if (j < c - 1 && cell[i][j + 1] == -1)
            {
                cell[i][j + 1] = dist;
                if (grid[i][j + 1] == 1)
                {
                    minDist = min(minDist, dist);
                }
                bfs.push({i, j + 1});
            }
        }

        // after one complete round increase the distance by 1
        dist += 1;
    }

    return minDist-1;
}

int main()
{

    return 0;
}