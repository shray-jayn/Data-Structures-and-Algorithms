#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int pivotIndex(vector<int> &nums)
{
    int n = nums.size();

    int prefix_sum = 0;

    for (int i = 0; i < n; i++)
    {
        prefix_sum += nums[i];
    }

    int left_sum = 0;
    int right_sum = prefix_sum;

    for (int i = 0; i < n; i++)
    {
        right_sum = right_sum - nums[i];

        if (left_sum == right_sum)
        {
            return i;
        }

        left_sum += nums[i];
    }

    return -1;
}

int main()
{

    return 0;
}