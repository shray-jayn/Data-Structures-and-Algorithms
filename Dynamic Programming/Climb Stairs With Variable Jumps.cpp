#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(int arr[], int n, vector<int> &dp)
{
    dp[n] = 1;

    for (int i = n-1; i>=0; i--)
    {
        for (int j = 1; j < arr[i] and i + j <= n + 1; i++)
        {
            dp[i] += dp[i + j];
        }
    }

    return dp[0];
}

int cs(int arr[], int n)
{
    vector<int> dp(n + 1);
    return solve(arr, n, dp);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << cs(arr, n) << endl;

    return 0;
}