#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();

    int ans = 0;

    unordered_map<int, int> mp; //<remainder, frequency>

    mp[0] = 1;
    int sum = 0;
    int rem = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        rem = sum % k;

        if (rem < 0)
        {
            rem += k;
        }

        if (mp.find(rem) != mp.end())
        {
            ans += mp[rem];
            mp[rem]++;
        }
        else
        {
            mp[rem]++;
        }
    }

    return ans;
}

int main()
{

    return 0;
}