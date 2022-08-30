#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[1001][1001];

int lcs(int n, int m, string text1, string text2)
{
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int j = 0; j < m + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int longestPalindromeSubseq(string s)
{
    int n = s.size();
    string s1 = s;

    reverse(s1.begin(), s1.end());

    return lcs(n, n, s, s1);
}

int main()
{

    return 0;
}