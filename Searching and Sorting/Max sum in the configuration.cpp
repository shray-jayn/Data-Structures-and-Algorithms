#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maximizeSum(vector<int> arr)
{
    int n = arr.size();

    int sum = 0;
    int s0 = 0;

    for (int i = 0; i < n; i++)
    {
        s0 += arr[i] * i;
        sum += arr[i];
    }

    int maxSum = s0;

    int si = s0;

    for (int i = 0; i < n - 1; i++)
    {
        int si_ = si + sum - n * (arr[n - i - 1]);
        maxSum = max(maxSum, si_);

        si = si_;
    }

    return maxSum;
}

int max_sum(int A[], int N)
{
}
