#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
{
    int n = nums.size();
    vector<int> prefixSum(n + 1, 0);

    int maxSum = 0;

    // building the prefix sums
    
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    // selecting the firstLen length subarray

    for (int i = 0; i <= n - firstLen; i++)
    {
        int lsum = prefixSum[i + firstLen] - prefixSum[i];

        // looking left

        for (int j = 0; j <= i - secondLen; j++)
        {
            int msum = prefixSum[j + secondLen] - prefixSum[j];
            maxSum = max(maxSum, lsum + msum);
        }

        // looking right

        for (int j = i + firstLen; j <= n - secondLen; j++)
        {
            int msum = prefixSum[j + secondLen] - prefixSum[j];
            maxSum = max(maxSum, lsum + msum);
        }
    }
    return maxSum;
}

int main()
{

    return 0;
}