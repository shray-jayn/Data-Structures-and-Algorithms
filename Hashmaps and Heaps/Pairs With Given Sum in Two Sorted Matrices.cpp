#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(vector<vector<int>> num1, vector<vector<int>> num2, int k)
{
    int n = num1.size();
    int m = num2.size();

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < num1[i].size(); j++)
        {
            mp[num1[i][j]]++;
        }
    }

    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < num2[i].size(); j++)
        {
            int val = k - num2[i][j];

            if (mp.find(val) != mp.end())
            {
                count += mp[val];
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}