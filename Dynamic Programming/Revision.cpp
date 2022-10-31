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

// Subset Sum problem

bool subsetSum(vector<int> weight, int n, int sum)
{
    // Base Condition

    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }

    // Choice Diagram

    if (weight[n - 1] <= sum)
    {
        return (subsetSum(weight, n - 1, sum - weight[n - 1]) or subsetSum(weight, n - 1, sum));
    }
    else
    {
        return subsetSum(weight, n - 1, sum);
    }
}

// Unbounded 0/1 Knapsack

int unboundedKnapsack(vector<int> weight, vector<int> value, int n, int W)
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

        int takes = value[n - 1] + unboundedKnapsack(weight, value, n, W - weight[n - 1]);

        // Doesn't takes the

        int dontTakes = unboundedKnapsack(weight, value, n - 1, W);

        return max(takes, dontTakes);
    }

    else if (weight[n - 1] > W)
    {
        return unboundedKnapsack(weight, value, n - 1, W);
    }
}

// Coin change problem - MAX number of ways

int coinChange(vector<int> coins, int sum, int n)
{
    // base condition

    if (sum == 0 and n == 0)
    {
        return NULL;
    }

    if (n == 0)
    {
        return 0;
    }

    if (sum == 0)
    {
        return 1;
    }

    // choice diagram

    if (coins[n - 1] <= sum)
    {
        return coinChange(coins, sum - coins[n - 1], n) + coinChange(coins, sum, n - 1);
    }

    else
    {
        return coinChange(coins, sum, n - 1);
    }
}

// Coin change problem - Min Number of coins

int coinChange2(vector<int> coins, int sum, int n)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
            if (j == 0)
            {
                dp[i][j] = 0;
            }

            if (i == 0 and j == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (j % coins[0] == 0)
            {
                dp[i][j] = j / coins[0];
            }
            else
            {
                dp[i][j] = INT_MAX - 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

// Length of longest common subsequence (LCS)

// Recursive

int lcs(string s1, string s2, int n1, int n2)
{
    // Base conditon

    if (n1 == 0 or n2 == 0)
    {
        return 0;
    }

    // Choice diagram

    if (s1[n1 - 1] == s2[n2 - 1])
    {
        return 1 + lcs(s1, s2, n1 - 1, n2 - 1);
    }

    else
    {
        return max(lcs(s1, s2, n1 - 1, n2), lcs(s1, s2, n1, n2 - 1));
    }
}

// Memoization -> Bottom-up

int lcsHelper(string s1, string s2, int n1, int n2)
{
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

    return lcs(s1, s2, n1, n2, dp);
}

int lcs(string s1, string s2, int n1, int n2, vector<vector<int>> dp)
{
    // Base conditon

    if (n1 == 0 or n2 == 0)
    {
        return 0;
    }

    if (dp[n1][n2] != -1)
    {
        return dp[n1][n2];
    }

    // Choice diagram

    if (s1[n1 - 1] == s2[n2 - 1])
    {
        return dp[n1][n2] = 1 + lcs(s1, s2, n1 - 1, n2 - 1, dp);
    }

    else
    {
        return dp[n1][n2] = max(lcs(s1, s2, n1 - 1, n2, dp), lcs(s1, s2, n1, n2 - 1, dp));
    }
}
// Top-down
int lcs(string s1, string s2, int n1, int n2)
{
    int dp[n1 + 1][n2 + 1];

    for (int i = 0; i < n1 + 1; i++)
    {
        for (int j = 0; j < n2 + 1; j++)
        {
            if (i == 0 or j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n1 + 1; i++)
    {
        for (int j = 1; j < n2 + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n1][n2];
}

// Matrix chain multiplication 


// Palindrome Partition problem 


// Scrambled strings


//Egg dropping problem 


// Evaluate expression to true 


// Optimal Binary search tree 





