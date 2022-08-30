#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
{
    int start = 0;
    int end = 0;

    int n = nums.size();

    int ans = 0;

    int prevCount = 0;

    while (end < n)
    {
        // CASE 1 : curr element is in the given range

        if (left <= nums[end] and right >= nums[end])
        {
            prevCount = end - start + 1;
            ans += prevCount;
        }

        // CASE 2 : curr element is less than left

        else if (nums[end] < left)
        {
            ans += prevCount;
        }

        // CASE 3 : curr element is greater than right

        else if (nums[end] > right)
        {
            start = end + 1;
            prevCount = 0;
        }

        end++;
    }

    return ans;
}

int main()
{

    return 0;
}