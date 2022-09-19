#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    vector<vector<int>> mergedIntervals;

    if (n == 0)
    {
        return mergedIntervals;
    }

    sort(intervals.begin(), intervals.end());

    vector<int> pre_interval = intervals[0];

    for (auto interval : intervals)
    {
        if (interval[0] <= pre_interval[1]) // means there is overlapping of intervals
        {
            pre_interval[1] = max(pre_interval[1], interval[1]); // need to check which has max ending points hence we will make ending point of pre_interval to max
        }

        else // means there is NO overlapping of intervals
        {
            mergedIntervals.push_back(pre_interval);
            pre_interval = interval;
        }
    }

    mergedIntervals.push_back(pre_interval);
    return mergedIntervals;
}

int main()
{

    return 0;
}