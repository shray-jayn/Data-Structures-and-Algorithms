#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool solve(vector<int> &time, long long trips, long long t)
{
    int n = time.size();
    long long cnt = 0;
    
    for (int i = 0; i < n; i++)
    { // for present t, evaluating how many trips are possible.
        cnt += (t / time[i]);
    }
    if (cnt >= trips)
        return true; // if the cnt is greater than or equal to required trips, then return true, else false.
    return false;
}

long long minimumTime(vector<int> &time, int trips)
{
    int minm = INT_MAX;
    for (int i = 0; i < time.size(); i++)
    { // finding minm element
        minm = min(minm, time[i]);
    }
    long long l = 0, r = ((long long)minm) * trips; // lower bound and upper bound for ans.
    long long ans = 0;
    while (l <= r)
    { // binary search over the time range
        long long mid = l + (r - l) / 2;
        if (solve(time, trips, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
int main()
{

    vector<int> v = {1, 2, 3};
    int k = 5;

    cout << minimumTime(v, k) << endl;

    return 0;
}