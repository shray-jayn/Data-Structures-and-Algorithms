#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));

    for (int i = dp.size() - 1; i >= 0; i--)
    {
        for (int j = dp[0].size() - 1; j >= 0; j--)
        {
            if (i == dp.size() - 1 and j == dp[0].size() - 1) // last row last col
            {
                dp[i][j] = true;
            }

            else if (i == dp.size() - 1) // last row
            {
                dp[i][j] = false;
            }

            else if (j == dp[0].size() - 1) // last col
            {
                if (p[i] == '*')
                {
                    dp[i][j] = dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = false;
                }
            }

            else
            {
                if (p[i] == '?')
                {
                    dp[i][j] = dp[i + 1][j + 1]; // diagonal me dekhekge
                }

                else if (p[i] == '*')
                {
                    dp[i][j] = dp[i + 1][j] or dp[i][j + 1]; // vertical or horizontal position ka OR lenge
                }

                else if (p[i] == s[i])
                {
                    dp[i][j] = dp[i + 1][j + 1]; // diagonal me dekhekge
                }
                else // char same na aye
                {
                    dp[i][j] = false;
                }
            }
        }
    }

    return dp[0][0];
}

int main()
{

    return 0;
}