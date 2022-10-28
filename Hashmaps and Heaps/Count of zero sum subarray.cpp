#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countOfZeroSumSubarray(vector<int> arr)
{
    int n = arr.size();
    int count = 0;

    unordered_map<int, int> mp;

    int i = -1;
    int sum = 0;

    mp[sum] = 1;

    while (i < n - 1)
    {
        i++;
        sum += arr[i];

        if (mp.find(sum) != mp.end())   // purana sum mila to count me uski freq add kardo or uski freq bada do phir
        {
            count += mp[sum];
            mp[sum]++;
        }
        else
        {
            mp[sum]++;
        }
    }

    return count;
}

int main()
{

    return 0;
}