#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    int ans = LONG_LONG_MAX;

    sort(a.begin(), a.end());

    for (int i = 0; i < n - m; i++)
    {
        int minWindow = a[i];
        int maxWindow = a[i + m - 1];

        int gap = maxWindow - minWindow;

        ans = max(ans, gap);
    }

    return ans;
}

int main()
{

    return 0;
}