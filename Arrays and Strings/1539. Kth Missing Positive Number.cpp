#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();

    int before = arr[0] - 1;
    int missing = 0;

    if (before != 0)
    {
        int diff = before;

        if (k > diff)
        {
            k -= diff;
            missing += diff;
        }
        else if (k <= diff)
        {
            return k;
        }
    }

    for (int i = 1; i < n; i++)
    {
        int diff = arr[i] - arr[i - 1];

        if (diff == 1)
        {
            continue;
        }
        else
        {
            diff = diff - 1;

            if (k > diff)
            {
                k -= diff;
                missing = diff + arr[i - 1];
            }
            else if (k <= diff)
            {
                return arr[i - 1] + k;
            }
        }
    }

    return arr[n - 1] + k;
}

int compute(int actual, int expected)
{
    return actual - expected;
}

int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();

    int left = 0;
    int right = n - 1;

    int missing = compute(arr[n - 1], n);

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        missing = compute(arr[mid], mid + 1);

        if (missing >= k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    // Right becomes -1
    if (right == -1)
    {
        return k;
    }

    return arr[right] + k - compute(arr[right], right + 1);
}

int main()
{

    return 0;
}