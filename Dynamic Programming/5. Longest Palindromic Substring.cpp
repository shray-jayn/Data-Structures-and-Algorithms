#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[1001][1001];

int lcs(int n, int m, string a, string b)
{
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i < m + 1; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {

            if (a[n - 1] == b[m - 1])
            {
                dp[n][m] = 1 + lcs(n - 1, m - 1, a, b);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    int maxLen = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            maxLen = max(maxLen, dp[i][j]);
        }
    }

    return maxLen;
}

int countSubstrings(string s)
{
    int n = s.size();
    string a = s;

    reverse(a.begin(), a.end());

    return lcs(n, n, s, a);
}

int main()
{

    return 0;
}