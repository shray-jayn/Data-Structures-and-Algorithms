#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(int n)
{
    vector<int> dp(n + 1, 0);

    dp[1] = 1;

    int p2 = 1;
    int p3 = 1;
    int p5 = 1;

    for (int i = 2; i <= n; i++)
    {
        int f1 = 2 * dp[p2];
        int f2 = 3 * dp[p3];
        int f3 = 5 * dp[p5];

        int minNo = min(f1, min(f2, f3));

        dp[i] = minNo;

        if (minNo == f1)
        {
            p2++;
        }
        if (minNo == f1)
        {
            p3++;
        }
        if (minNo == f1)
        {
            p5++;
        }
    }

    return dp[n];
}

int main()
{

    return 0;
}