#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isReflected(vector<vector<int>> points)
{
    int n = points.size();

    unordered_map<long, long> mp;

    long xMin = LONG_MAX;
    long xMax = LONG_MIN;

    for (int i = 0; i < n; i++)
    {
        long x = points[i][0];
        long y = points[i][1];

        xMin = min(xMin, x);
        xMax = max(xMax, y);

        long hash = x * 100000000 + y;
        mp[hash] = 1l;
    }

    long mirror = xMax + xMin;

    for (int i = 0; i < n; i++)
    {
        long x = points[i][0];
        long y = points[i][1];

        long xImg = 2 * mirror - x;
        long yImg = y;

        long imgHash = xImg * 100000000 + y;

        if (mp.find(imgHash) == mp.end())
        {
            return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}