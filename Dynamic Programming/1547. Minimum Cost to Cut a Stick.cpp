#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[103][103];

int solve(int i, int j, vector<int> &cuts)
{

    // base case

    if (j - i == 1) // cannot cut more
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int length = cuts[j] - cuts[i];
    int ans = INT_MAX;

    for (int k = i + 1; k < j; k++)
    {
        int temp = solve(i, k, cuts) + solve(k, j, cuts) + length;

        ans = min(ans, temp);
    }

    return dp[i][j] = ans;
}

int minCost(int n, vector<int> &cuts)
{
    memset(dp, -1, sizeof(dp));

    cuts.push_back(0);
    cuts.push_back(n);

    sort(cuts.begin(), cuts.end());

    return solve(0, cuts.size() - 1, cuts);
}

int main()
{

    return 0;
}