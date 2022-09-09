#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int LargestSubarrayWith0Sum(vector<int> &arr)
{
    int n = arr.size();

    unordered_map<int, int> mp;

    int sum = 0;
    int maxLen = 0;

    mp[sum] = -1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (mp.find(sum) != mp.end())
        {
            int len = i - mp[sum];
            maxLen = max(maxLen, len);
        }
        else
        {
            mp[sum] = i;
        }
    }

    return maxLen;
}

int main()
{

    return 0;
}