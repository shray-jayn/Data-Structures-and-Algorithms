#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findMaxLength(vector<int> &arr)
{
    int n = arr.size();

    int ans = 0;

    unordered_map<int, int> mp; //<sum,index>

    mp[0] = -1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            sum += -1;
        }
        else if (arr[i] == 1)
        {
            sum += 1;
        }

        if (mp.find(sum) != mp.end())
        {
            int idx = mp[sum];
            int len = i - idx;

            ans = max(ans, len);
        }
        else
        {
            mp[sum] = i;
        }
    }

    return ans;
}

int main()
{

    return 0;
}