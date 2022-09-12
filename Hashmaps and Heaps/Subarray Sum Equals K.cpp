#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();

    int ans = 0;
    unordered_map<int, int> mp;

    mp[0] = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        int remainingSum = sum - k;

        if (mp.find(remainingSum) != mp.end())
        {
            ans += mp[remainingSum];
        }

        mp[sum]++;
    }

    return ans;
}

int main()
{

    return 0;
}