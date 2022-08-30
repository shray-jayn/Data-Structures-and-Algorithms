#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[2001][2001];

bool isPalindrome(string &s, int i, int j)
{

    if (i == j)
    {
        return true;
    }
    if (i > j)
    {
        return true;
    }

    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(int i, int j, string &s)
{
    if (i >= j)
    {
        return 0;
    }

    if (isPalindrome(s, i, j) == true)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = INT_MIN;

    for (int k = i; k < j; k++)
    {
        int temp = solve(i, k, s) + solve(k + 1, j, s) + 1;

        ans = max(ans, temp);
    }

    return dp[i][j] = ans;
}

int minCut(string s)
{
    int i = 0;
    int j = s.size() - 1;
    memset(dp, -1, sizeof(dp));
    return solve(i, j, s);
}

int main()
{

    return 0;
}