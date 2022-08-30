#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Recursive code

int solve(vector<int> &cost, int i)
{
    if (i >= cost.size()) // out of bound
    {
        return 0;
    }

    if (i == cost.size() - 1) // last index
    {
        return cost[i];
    }

    int c1 = solve(cost, i + 1) + cost[i];
    int c2 = solve(cost, i + 2) + cost[i];

    return min(c1, c2);
}

int minCostClimbingStairs(vector<int> &cost)
{
    return min(solve(cost, 0), solve(cost, 1));
}

// Memoizeation (Top -> down )

int solve(vector<int> &cost, int i, vector<int> &dp)
{
    if (i >= cost.size()) // out of bound
    {
        return 0;
    }

    if (i == cost.size() - 1) // last index
    {
        return cost[i];
    }

    if (dp[i] != 0)
    {
        return dp[i];
    }

    int c1 = solve(cost, i + 1, dp) + cost[i];
    int c2 = solve(cost, i + 2, dp) + cost[i];

    return dp[i] = min(c1, c2);
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size() - 1;

    vector<int> dp(n, 0);
    return min(solve(cost, 0, dp), solve(cost, 1, dp));
}

// Tabulation (Bottom - up )

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();

    vector<int> dp(n + 1, 0);

    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
    }
    
    return dp[n];
}
