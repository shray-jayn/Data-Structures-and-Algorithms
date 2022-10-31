#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// 0-1 Knapsack Problem

// Recursive Code

int knapsack(vector<int> weight, vector<int> value, int n, int W)
{
    // Base condition

    if (n == 0 or W == 0)
    {
        return 0;
    }

    // choise diagram

    if (weight[n - 1] <= W)
    {
        // takes the weight

        int takes = value[n - 1] + knapsack(weight, value, n - 1, W - weight[n - 1]);

        // Doesn't takes the

        int dontTakes = knapsack(weight, value, n - 1, W);

        return max(takes, dontTakes);
    }

    else if (weight[n - 1] > W)
    {
        return knapsack(weight, value, n - 1, W);
    }
}

// Memoization  ==> Bottom Up

int static dp[102][1002]; // [n+1][W+1]

// memset(dp, -1, sizeof(dp));

int knapsack(vector<int> weight, vector<int> value, int n, int W)
{
    // Base condition

    if (n == 0 or W == 0)
    {
        return 0;
    }

    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    // choise diagram

    if (weight[n - 1] <= W)
    {
        // takes the weight

        int takes = value[n - 1] + knapsack(weight, value, n - 1, W - weight[n - 1]);

        // Doesn't takes the

        int dontTakes = knapsack(weight, value, n - 1, W);

        return dp[n][W] = max(takes, dontTakes);
    }

    else if (weight[n - 1] > W)
    {
        return dp[n][W] = knapsack(weight, value, n - 1, W);
    }
}

// Top-Down Approach

int knapSack(vector<vector<int>> dp, int n, int W, vector<int> &weight, vector<int> &values)
{
    // Base case

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 or j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    // Choice diagram

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }

            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main()
{

    return 0;
}