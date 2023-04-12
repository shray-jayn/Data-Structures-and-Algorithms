#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isValid(vector<int> &nums, int n, int maxOperations, int mid)
{
    int reqOperations = 0;

    for (int i = 0; i < n; i++)
    {
        int x = n / mid;

        if (n % mid == 0)
        {
            x--;
        }
        reqOperations += x;
    }

    if (reqOperations <= maxOperations)
    {
        return true;
    }
    return false;
}

int minimumSize(vector<int> &nums, int maxOperations)
{
    int n = nums.size();
    int maxVal = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxVal = max(maxVal, nums[i]);
    }

    int start = 1;
    int end = maxVal;

    int ans = maxVal; // inially ans would the maximum value

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isValid(nums, n, maxOperations, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{

    return 0;
}