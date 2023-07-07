#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(int row, int col, vector<vector<int>> &grid, int n, int m)
{
    if (row < 0 or row >= n or col < 0 or col >= m)
    {
        return;
    }
    if (grid[row][col] == 2 or grid[row][col] == 1)
    {
        return;
    }

    grid[row][col] = 2;

    dfs(row + 1, col, grid, n, m);
    dfs(row - 1, col, grid, n, m);
    dfs(row, col + 1, grid, n, m);
    dfs(row, col - 1, grid, n, m);
}

int closedIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1 and grid[i][j] == 0)
            {
                dfs(i, j, grid, n, m);
            }
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                dfs(i, j, grid, n, m);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0}};

    cout << closedIsland(grid) << endl;

    return 0;
}