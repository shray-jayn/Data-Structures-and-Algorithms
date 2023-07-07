#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(int i, int j, vector<vector<int>> &grid)
{
    int n = grid.size();

    if (i < 0 or i >= n or j < 0 or j >= n or grid[i][j] == 0)
    {
        return;
    }

    grid[i][j] = 0;

    int row = i;
    int col = j;

    for (int r = row; r >= 0; r--)
    {
        if (grid[r][col] == 1)
        {
            dfs(r, col, grid);
        }
    }

    for (int r = row; r < n; r++)
    {
        if (grid[r][col] == 1)
        {
            dfs(r, col, grid);
        }
    }

    for (int c = col; c >= 0; c--)
    {
        if (grid[row][c] == 1)
        {
            dfs(row, c, grid);
        }
    }

    for (int c = col; c < n; c++)
    {
        if (grid[row][c] == 1)
        {
            dfs(row, c, grid);
        }
    }
}

int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();

    vector<vector<int>> grid(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        int row = stones[i][0];
        int col = stones[i][1];

        grid[row][col] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(i, j, grid);
                grid[i][j] = 1;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                count++;
            }
        }
    }

    return n - count;
}

int main()
{

    return 0;
}