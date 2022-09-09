#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int maximumSumSubarray(int k, vector<int> &arr, int n)
{
    // code here

    int sum = 0;

    int maxSum = INT_MIN;

    int i = 0, j = k;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    maxSum = max(sum, maxSum);

    while (j < n)
    {
        sum += arr[j];
        j++;
        sum -= arr[i];
        i++;
        maxSum = max(sum, maxSum);
    }

    return maxSum;
}

int main()
{

    return 0;
}