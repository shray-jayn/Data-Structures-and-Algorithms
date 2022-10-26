#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> square(int arr[], int n)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    int maxArea = 0;
    int sq = 0;

    for (auto it : mp)
    {
        int key = it.first;
        int freq = it.second;

        if (freq >= 4)
        {
            int area = key * key;

            if (area > maxArea)
            {
                maxArea = area;
                sq = freq / 4;
            }
        }
    }

    vector<int> ans;

    if (maxArea == 0)
    {
        ans.push_back(-1);
    }
    else
    {
        ans.push_back(maxArea);
        ans.push_back(sq);
    }

    return ans;
}
