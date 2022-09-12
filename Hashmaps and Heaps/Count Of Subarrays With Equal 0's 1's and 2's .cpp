#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countSubarrayEqual012(vector<int> arr)
{
    int n = arr.size();

    int ans = 0;
    unordered_map<string, int> mp; //<key ,index>

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    int delta10 = count1 - count0;
    int delta21 = count2 - count1;

    string key = delta21 + "3" + delta10;
    mp[key] = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }

        delta10 = count1 - count0;
        delta21 = count2 - count1;

        key = delta21 + "#" + delta10;

        if (mp.find(key) != mp.end())
        {
            ans += mp[key];
            mp[key]++;
        }
        else
        {
            mp[key]++;
        }
    }

    return ans;
}

int main()
{

    return 0;
}