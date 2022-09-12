#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> anagramsMappings(vector<int> arr1, vector<int> arr2)
{
    int n = arr1.size();

    unordered_map<int, queue<int>> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr2[i]].push(i);
    }

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        queue<int> q = mp[arr1[i]];
        int val = q.front();
        ans[i] = val;
    }

    return ans;
}

int main()
{

    return 0;
}