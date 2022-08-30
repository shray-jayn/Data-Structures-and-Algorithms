#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(int *arr, int n, int i, vector<int> &dp)
{
    if (i >= n)
    {
        return 0;
    }

    if (dp[i] != 0)
    {
        return dp[i];
    }

    int a = arr[i] + solve(arr, n, i + 2, dp);
    int b = solve(arr, n, i + 1, dp);

    return dp[i] = max(a, b);
}

int findMaxSum(int *arr, int n)
{
    vector<int> dp(n + 1, 0);
    return solve(arr, n, 0, dp);
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

    int a = findMaxSum(arr, n);
    cout << a << endl;

    return 0;
}