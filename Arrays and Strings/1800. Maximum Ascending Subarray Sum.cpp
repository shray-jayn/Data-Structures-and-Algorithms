#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxAscendingSum(vector<int> &nums)
{
    int n = nums.size();

    int maxSum = nums[0];
    int sum = nums[0];

    int prev = nums[0];

    cout << "maxSum = " << maxSum << endl;
    cout << "sum = " << sum << endl;

    for (int i = 1; i < n; i++)
    {

        int cur = nums[i];

        if (cur > prev)
        {
            sum += cur;
        }
        else
        {
            sum = 0;
            sum += cur;
        }
        maxSum = max(maxSum, sum);
        prev = cur;

        cout << "maxSum = " << maxSum << endl;
        cout << "sum = " << sum << endl;
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {100, 10, 1};

    cout << maxAscendingSum(nums) << endl;

    return 0;
}