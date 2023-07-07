#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(int i, int j, int n, int m, vector<vector<int>> &grid, int &count)
{
    if (i < 0 or i >= n or j < 0 or j >= m)
    {
        return;
    }
    if (grid[i][j] == 1)
    {
        count++;
        grid[i][j] = 0; // mark as visited
    }

    int row = i;
    int col = j;

    // go up in their row

    for (int r = row; r >= 0; r--)
    {
        if (grid[r][j] == 1)
            dfs(r, j, n, m, grid, count);
    }
    for (int r = row; r < n; r++)
    {
        if (grid[r][j] == 1)
            dfs(r, j, n, m, grid, count);
    }
    for (int c = col; c >= 0; c--)
    {
        if (grid[i][c] == 1)
            dfs(i, c, n, m, grid, count);
    }
    for (int c = col; c < m; c++)
    {
        if (grid[i][c] == 1)
            dfs(i, c, n, m, grid, count);
    }
}

int countServers(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                int count = 0;

                dfs(i, j, n, m, grid, count);

                if (count > 1)
                {
                    ans += count;
                }
            }
        }
    }

    return ans;
}

int main()
{
    // vector<vector<int>> grid = {{1, 0}, {0, 1}};
    vector<vector<int>> grid = {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

    cout << countServers(grid) << endl;

    return 0;
}