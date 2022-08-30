#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(vector<vector<int>> &dp, string a, string b, int n, int m)
{

    if (n == 0 or m == 0)
    {
        return 0;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (a[n - 1] == b[m - 1] and m - 1 != n - 1)
    {
        return dp[n][m] = 1 + solve(dp, a, b, n - 1, m - 1);
    }

    else
    {
        return dp[n][m] = max(solve(dp, a, b, n - 1, m), solve(dp, a, b, n, m - 1));
    }
}

int LongestRepeatingSubsequence(string str)
{
    // Code here

    int n = str.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return solve(dp, str, str, n, n);
}

int main()
{

    return 0;
}