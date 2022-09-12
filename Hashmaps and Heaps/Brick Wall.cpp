#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int leastBricks(vector<vector<int>> &wall)
{
    int n = wall.size();

    unordered_map<int, int> mp;

    int maxFreq = 0;

    for (int i = 0; i < n; i++)
    {
        int ps = 0;

        for (int j = 0; j < wall[i].size()-1; j++)
        {
            ps += wall[i][j];
            mp[ps]++;

            maxFreq = max(maxFreq, mp[ps]);
        }
    }

    return n - maxFreq;
}

int main()
{

    return 0;
}