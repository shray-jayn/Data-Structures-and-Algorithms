#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void bfs(vector<vector<int>> &grid, vector<vector<int>> &dis)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                q.push({i, j});
                dis[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {

        auto point = q.front();
        q.pop();

        int x = point.first;
        int y = point.second;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 or nx >= grid.size() or ny < 0 or ny >= grid[nx].size() or grid[nx][ny] == 0 or dis[nx][ny] != -1)
                continue;
            q.push({nx, ny});
            dis[nx][ny] = dis[x][y] + 1;
        }
    }
}
vector<vector<int>> updateMatrix(vector<vector<int>> &grid)
{
    vector<vector<int>> dis(grid.size(), vector<int>(grid[0].size(), -1));
    bfs(grid, dis);
    return dis;
}

int main()
{

    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};

    vector<vector<int>> ans = updateMatrix(mat);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}