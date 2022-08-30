#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countPalindromicSubsequences(string s)
{
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    vector<int> prev(n);
    unordered_map<char, int> mp;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (mp.find(ch) == mp.end())
        {
            prev[i] = -1;
        }

        else
        {
            prev[i] = mp[ch];
        }

        mp[ch] = i;
    }

    vector<int> next(n);
    mp.clear();

    for (int i = n - 1; i >= 0; i--)
    {
        char ch = s[i];

        if (mp.find(ch) == mp.end())
        {
            next[i] = -1;
        }

        else
        {
            next[i] = mp[ch];
        }

        mp[ch] = i;
    }

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (gap == 1)
            {
                dp[i][j] = 2;
            }
            else
            {
                char sc = s[i]; // start char
                char ec = s[j]; // end char

                if (sc != ec)
                {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }

                else
                {
                    int nis = next[i]; // next index of starting
                    int pie = prev[j]; // prev index of end

                    if (nis > pie)
                    {
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
                    }

                    else if (nis == pie)
                    {
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
                    }
                    else
                    {
                        dp[i][j] = 2 * dp[i + 1][j - 1] - dp[nis + 1][pie - 1];
                    }
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{

    return 0;
}