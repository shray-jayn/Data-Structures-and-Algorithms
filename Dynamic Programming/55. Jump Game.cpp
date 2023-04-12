#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool canJump(vector<int> &nums)
{

    int n = nums.size();
    int reachable = 0;

    for (int i = 0; i < n; i++)
    {
        if (i > reachable)
        {
            return false;
        }

        reachable = max(reachable, i + nums[i]);
    }
    return true;
}

// recursive code

bool canJump(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n + 1, -1);

    return jumps(nums, dp, 0);
}

bool jumps(vector<int> &nums, vector<int> &dp, int idx)
{
    if (idx == nums.size() - 1) // reached end
    {
        return true;
    }

    if (nums[idx] == 0) // dead end can't go further
    {
        return false;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int possibleJumps = nums[idx];

    for (int i = 1; i <= possibleJumps; i++)
    {
        if (jumps(nums, dp, i + idx) == true)
        {
            dp[idx + i] = 1;
            return true;
        }
    }
    dp[idx] = 0;
    return false;
}

int main()
{

    return 0;
}