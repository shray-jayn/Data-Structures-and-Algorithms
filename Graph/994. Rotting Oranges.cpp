#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isValid(int x, int y, int m, int n)
{
    if (x >= 0 and x < m and y >= 0 and y < n)
    {
        return true;
    }

    return false;
}

int orangesRotting(vector<vector<int>> &grid)
{
    vector<int> time;

    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }

    int count = 0;

    while (fresh != 0 and !q.empty())
    {
        int qw = q.size();
        while (qw--)
        {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if (isValid(x + 1, y, m, n) and grid[x + 1][y] == 1)
            {
                q.push({x + 1, y});
                grid[x + 1][y] = 2;
                fresh--;
            }
            if (isValid(x - 1, y, m, n) and grid[x - 1][y] == 1)
            {
                q.push({x - 1, y});
                grid[x - 1][y] = 2;
                fresh--;
            }
            if (isValid(x, y + 1, m, n) and grid[x][y + 1] == 1)
            {
                q.push({x, y + 1});
                grid[x][y + 1] = 2;
                fresh--;
            }
            if (isValid(x, y - 1, m, n) and grid[x][y - 1] == 1)
            {
                q.push({x, y - 1});
                grid[x][y - 1] = 2;
                fresh--;
            }
        }
        count++;
    }

    if (fresh != 0)
    {
        return -1;
    }
    return count;
}

int main()
{

    return 0;
}