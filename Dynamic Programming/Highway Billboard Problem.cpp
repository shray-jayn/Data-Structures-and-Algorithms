#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxProfit(int m, vector<int> profit, vector<int> dist, int minDist)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < m; i++)
    {
        mp[dist[i]] = profit[i];
    }

    vector<int> dp(m + 1, 0);

    dp[0] = 0;

    for (int i = 1; i <= m; i++)
    {
        if (mp.find(i) == mp.end()) // does not contain key
        {
            dp[i] = dp[i - 1]; // jo pichle vale ki value hai vo dal do
        }

        else
        {
            int boardNotInstalled = dp[i - 1];
            
            int boardInstalled = mp[i]; // current board ka profit + pichle board ka profit jo mindist piche hai

            if (i - minDist - 1 >= 0)
            {
                boardInstalled += dp[i - minDist - 1];
            }

            dp[i] = max(boardInstalled, boardNotInstalled);
        }
    }

    return dp[m];
}
int main()
{

    return 0;
}