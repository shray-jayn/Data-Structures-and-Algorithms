#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
class Solution
{
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    void DFS(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, int n, int m, int &res)
    {
        if (min(i, j) < 0 or i >= n or j >= m or !grid2[i][j])
            return;

        if (grid1[i][j] == 0 and grid2[i][j] == 1)
        {
            res = false;
        }

        grid2[i][j] = 0;
        
        for (int k = 0; k < 4; ++k)
        {
            DFS(grid1, grid2, i + dx[k], j + dy[k], n, m, res);
        }
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int ans = 0)
    {
        int n = grid1.size(), m = grid1[0].size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid2[i][j])
                {
                    int res = true;
                    DFS(grid1, grid2, i, j, n, m, res);
                    ans += res;
                }
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}