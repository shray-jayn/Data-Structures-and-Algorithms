#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(int i, int j, vector<int> &values, vector<vector<int>> &dp)
{
    if (j - i + 1 < 3)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = INT_MAX;

    for (int k = i + 1; k <= j - 1; k++)
    {
        int left = solve(i, k, values, dp);
        int right = solve(k, j, values, dp);
        int cost = values[i] * values[j] * values[k];

        int temp = left + right + cost;

        ans = min(temp, ans);
    }

    return dp[i][j] = ans;
}

int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(0, n - 1, values, dp);
}

int main()
{

    return 0;
}