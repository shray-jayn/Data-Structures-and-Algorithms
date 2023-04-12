#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if (k <= 1)
    {
        return 0;
    }

    int n = nums.size();

    int i = 0, j = 0;
    int ans = 0;
    int product = 1;

    while (j < n)
    {
        product *= nums[j];

        if (product < k)
        {
            ans += j - i + 1;
            j++;
        }
        else if (product >= k)
        {
            while (product >= k)
            {
                product /= nums[i];
                i++;
            }

            ans += j - i + 1;
            j++;
        }
    }

    return ans;
}

int main()
{
    // vector<int> nums = {10, 5, 2, 6};
    // int k = 100;

    vector<int> nums = {1, 1, 1, 1};
    int k = 1;

    cout << numSubarrayProductLessThanK(nums, k) << endl;

    return 0;
}