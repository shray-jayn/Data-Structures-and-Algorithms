#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Memoization

int solve(vector<vector<int>> &dp, int i, int j, vector<int> &nums)
{
    if (i > j)
    {
        return 0;
    }

    if (i == j)
    {
        return nums[i];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int a = nums[i] + min(solve(dp, i + 2, j, nums), solve(dp, i + 1, j - 1, nums));
    int b = nums[j] + min(solve(dp, i + 1, j - 1, nums), solve(dp, i, j - 2, nums));

    return dp[i][j] = max(a, b);
}

// Tablulation

bool PredictTheWinner(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    int player1Sum = solve(dp, 0, n - 1, nums);

    int player2Sum = sum - player1Sum;

    if (player2Sum > player1Sum)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}

// Tablulation

bool PredictTheWinner(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int gap = 0; gap < dp.size(); gap++)
    {
        for (int i = 0, j = 0; j < dp.size(); i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = nums[i];
            }

            else if (gap == 1)
            {
                dp[i][j] = max(nums[i], nums[j]);
            }

            else
            {
                int val1 = nums[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int val2 = nums[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);

                dp[i][j] = max(val1, val2);
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{

    return 0;
}