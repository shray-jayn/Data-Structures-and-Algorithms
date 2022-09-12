#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countEqualNum1and0(vector<int> arr)
{
    int n = arr.size();

    int ans = 0;

    unordered_map<int, int> mp; //
    mp[0] = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            sum += -1;
        }
        else
        {
            sum += 1;
        }

        if (mp.find(sum) != mp.end())
        {
            ans += mp[sum];
            mp[sum]++;
        }
        else
        {
            mp[sum]++;
        }
    }

    return ans;
}

int main()
{

    return 0;
}