#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (mp.find(target - nums[i]) != mp.end()) // if(mp.count(target-nums[i]))
        {
            return {mp[target - nums[i]], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}

int main()
{

    return 0;
}