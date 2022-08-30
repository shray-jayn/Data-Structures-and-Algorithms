#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// recursive code

int climbStairs(int n)
{
    if (n == 0 or n == 1)
    {
        return 1;
    }

    return climbStairs(n - 1) + climbStairs(n - 2);
}



// memozation;



int solve(int n, vector<int> &dp)
{
    if (n == 1 or n == 0)
    {
        return 1;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, 0);

    return solve(n, dp);
}



// tabulation

int solve(int n, vector<int> &dp)
{
    for (int i = 0; i <= 1; i++)
    {
        dp[i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}



int main()
{
    int n;
    cin >> n;

    cout << climbStairs(n) << endl;
    return 0;
}