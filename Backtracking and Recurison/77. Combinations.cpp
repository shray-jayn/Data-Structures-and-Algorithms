#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> result;

void helper(int idx, int currSize, int k, vector<int> &ans, vector<int> &nums)
{
    if (currSize == k)
    {
        result.push_back(ans);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        ans.push_back(nums[i]);
        helper(i + 1, currSize + 1, k, ans, nums);
        ans.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }

    vector<int> ans;

    helper(0, 0, k, ans, nums);

    return result;
}

int main()
{

    return 0;
}