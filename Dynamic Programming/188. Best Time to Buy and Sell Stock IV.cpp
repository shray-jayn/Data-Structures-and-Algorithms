#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// T.c. = O(K.N.N)

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int transaction = 1; transaction <= k; transaction++)
    {
        for (int day = 1; day < n; day++)
        {
            int maxVal = dp[transaction][day - 1];

            for (int prevDays = 0; prevDays < day; prevDays++)
            {
                int ptilltm1 = dp[transaction - 1][prevDays]; // profit till t - 1 transaction

                int pth = prices[day] - prices[prevDays]; // profit of t'th transaction

                if (pth + ptilltm1 > maxVal)
                {
                    maxVal = pth + ptilltm1;
                }
            }

            dp[transaction][day] = maxVal;
        }
    }

    return dp[k][n - 1];
}

// OPTIMIZATION
// T.c. = O(K.N)

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int transaction = 1; transaction <= k; transaction++)
    {
        int maxVal = INT_MIN;

        for (int day = 1; day < n; day++)
        {
            if (dp[transaction - 1][day - 1] - prices[day - 1] > maxVal)
            {
                maxVal = dp[transaction - 1][day - 1] - prices[day - 1];
            }

            if (maxVal + prices[day] > dp[transaction][day - 1])
            {
                dp[transaction][day] = maxVal + prices[day];
            }
            else
            {
                dp[transaction][day] = dp[transaction][day - 1];
            }
        }
    }

    return dp[k][n - 1];
}

int main()
{

    return 0;
}