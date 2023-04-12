#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isValid(vector<int> &candies, int n, long long k, int mid)
{
    long long reqCandies = 0;

    for (int i = 0; i < n; i++)
    {
        reqCandies += (candies[i]) / mid;
    }

    if (reqCandies >= k)
    {
        return true;
    }

    return false;
}

int maximumCandies(vector<int> &candies, long long k)
{
    int n = candies.size();

    int maxVal = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxVal = max(maxVal, candies[i]);
    }

    int start = 1;
    int end = maxVal;

    int ans = end;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isValid(candies, n, k, mid))
        {
            ans = mid;
            end = mid = 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{

    return 0;
}