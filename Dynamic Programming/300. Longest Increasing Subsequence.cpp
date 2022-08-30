#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Recursive

int lengthOfLIS(vector<int> &nums)
{
    return solve(nums, 0, INT_MIN);
}
int solve(vector<int> &nums, int i, int prev)
{
    if (i >= nums.size())
        return 0;                                      // cant pick any more elements
    int take = 0, dontTake = solve(nums, i + 1, prev); // try skipping the current element
    if (nums[i] > prev)
        take = 1 + solve(nums, i + 1, nums[i]); // or pick it if it is greater than previous picked element
    return max(take, dontTake);                 // return whichever choice gives max LIS
}

// Memoization

vector<vector<int>> dp;
int lengthOfLIS(vector<int> &nums)
{
    dp.resize(nums.size(), vector<int>(1 + nums.size(), -1)); // dp[i][j] denotes max LIS starting from i when nums[j] is previous picked element
    return solve(nums, 0, -1);
}

int solve(vector<int> &nums, int i, int prev_i)
{
    if (i >= nums.size())
        return 0;
    if (dp[i][prev_i + 1] != -1)
        return dp[i][prev_i + 1];
    int take = 0, dontTake = solve(nums, i + 1, prev_i);
    if (prev_i == -1 || nums[i] > nums[prev_i])
        take = 1 + solve(nums, i + 1, i); // try picking current element if no previous element is chosen or current > nums[prev_i]
    return dp[i][prev_i + 1] = max(take, dontTake);
}

// Tabulation

vector<int> dp;  

int lengthOfLIS(vector<int> &nums)
{
    int ans = 1, n = nums.size();

    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1), ans = max(ans, dp[i]);
    return ans;
}
