#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(vector<int> &nums, int k, int sum1, int sum2, int i, int n)
{
    if (i == n)
    {
        if (sum1 >= k and sum2 >= k)
        {
            return 1;
        }

        return 0;
    }

    int takeA = solve(nums, k, sum1 + nums[i], sum2, i + 1, n);
    int takeB = solve(nums, k, sum1, sum2 + nums[i], i + 1, n);

    return takeA + takeB;
}

int countPartitions(vector<int> &nums, int k)
{
    return solve(nums, k, 0, 0, 0, nums.size());
}
int main()
{

    return 0;
}