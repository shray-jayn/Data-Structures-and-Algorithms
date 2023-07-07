#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[201][201];

int dfs(vector<vector<int>> &mat, int i, int j, int pre)
{
    if (i < 0 || j < 0 || i == mat.size() || j == mat[0].size() || pre >= mat[i][j])
    {
        return 0;
    }

    if (dp[i][j])
    {
        return dp[i][j];
    }

    int l = dfs(mat, i, j - 1, mat[i][j]);
    int r = dfs(mat, i, j + 1, mat[i][j]);
    int u = dfs(mat, i - 1, j, mat[i][j]);
    int d = dfs(mat, i + 1, j, mat[i][j]);

    return dp[i][j] = max({l, r, u, d}) + 1;
}



int countPaths(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();


}

int main()
{

    return 0;
}