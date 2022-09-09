#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> distinctElementsSizeK(vector<int> arr, int k)
{
    int n = arr.size();

    vector<int> result;
    unordered_map<int, int> mp;

    for (int i = 0; i < k - 1; i++) // insert first k-1 elements
    {
        mp[arr[i]]++;
    }

    for (int j = 0, i = k - 1; i < n;)
    {
        mp[arr[i]]++; // acquire

        result.push_back(mp.size()); // work

        // release

        int freq = arr[j];

        if (freq == 1)
        {
            mp.erase(arr[j]);
        }
        else
        {
            mp[arr[j]]--;
        }

        i++;
        j++;
    }

    return result;
}

int main()
{

    return 0;
}