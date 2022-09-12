#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int longestSubarraySumDivisibleByK(vector<int> arr, int k)
{
    int n = arr.size();

    int ans = 0;

    unordered_map<int, int> mp; //<remainder, index>
    int sum = 0;
    int rem = 0;

    mp[-1] = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        rem = sum % k;

        if (rem < 0)
        {
            rem += k;
        }

        if (mp.find(rem) != mp.end())
        {
            int idx = mp[rem];
            int len = i - idx;

            ans = max(ans, len);
        }
        else
        {
            mp[rem] = i;
        }
    }

    return ans;
}

int main()
{

    return 0;
}