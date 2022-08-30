#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maximalSquare(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int ans = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 and j == m - 1) // last cell
            {
                dp[i][j] = matrix[i][j] - '0';
            }

            else if (i == n - 1) // last row
            {
                dp[i][j] = matrix[i][j] - '0';
            }

            else if (j == m - 1) // last column
            {
                dp[i][j] = matrix[i][j] - '0';
            }
            else
            {
                if (matrix[i][j] - '0' == 0)
                {
                    dp[i][j] = 0;
                }

                else
                {
                    dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i + 1][j + 1], dp[i][j + 1]));

                    ans = max(ans, dp[i][j]);
                }
            }
        }
    }

    return ans * ans;
}

int main()
{

    return 0;
}