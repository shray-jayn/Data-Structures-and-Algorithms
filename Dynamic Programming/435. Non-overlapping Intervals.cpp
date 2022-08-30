#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    sort(intervals.begin(), intervals.end());

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "{" << intervals[i][0] << "-" << intervals[i][1] << "} ";
    // }

    vector<int> dp(n, 1);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            int a = intervals[i][0];
            int b = intervals[j][1];

            if (a >= b)
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = max(dp[i], ans);
    }

    // cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << dp[i] << " ";
    // }

    // cout << endl;

    return n - ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}};

    // vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    cout << eraseOverlapIntervals(intervals) << endl;
    return 0;
}