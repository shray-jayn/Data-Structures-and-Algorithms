#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countSubstrings(string s)
{
    int n = s.size();

    bool dp[n][n];

    int count = 0;

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }

            else // gap 2 or more
            {
                if (s[i] == s[j] and dp[i + 1][j - 1] == true)  
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }

            if (dp[i][j] == true)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}