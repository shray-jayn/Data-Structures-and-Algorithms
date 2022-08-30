#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[101][101];

int sum(int i, int j, int frq[])
{
    int s = 0;

    for (int k = i; k <= j; k++)
    {
        s += frq[k];
    }

    return s;
}

int mcm(int i, int j, int freq[])
{

    if (j < i)
    {
        return 0;
    }

    if (i == j)
    {
        return freq[i];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int sum1 = sum(i, j, freq);

    int ans = INT_MAX;

    for (int k = i; k <= j; k++)
    {
        ans = min(ans, mcm(i, k - 1, freq) + mcm(k + 1, j, freq));
    }

    return dp[i][j] = ans + sum1;
}

int optimalSearchTree(int keys[], int freq[], int n)
{

    memset(dp, -1, sizeof dp);
    
    return mcm(0, n - 1, freq);
}

int main()
{

    return 0;
}