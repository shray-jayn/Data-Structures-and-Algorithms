#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int kadaneAlgo(vector<int> &nums)
{
    int ans = INT_MIN;

    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        ans = max(ans, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return ans;
}

int kadanesOfTwo(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nums(n * 2);

    for (int i = 0; i < n; i++)
    {
        nums[i] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        nums[i + n] = arr[i];
    }

    return kadaneAlgo(nums);
}

int kConcatenationMaxSum(vector<int> &arr, int k)
{

    long long N = 1000000007;

    int ans = 0;

    long long sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    if (k == 1)
    {
        ans = kadaneAlgo(arr) % N;
    }

    else if (sum > 0) // kadames of 1 and last + sum (k-2) copies (last and first are same so first 2 copies ka nikalenge)
    {
        ans = (kadanesOfTwo(arr) + (k - 2) * sum) % N;
    }

    else // kadames of first 2 copies
    {
        kadanesOfTwo(arr) % N;
    }

    return ans % N;
}

long long N = 1000000007;

int kConcatenationMaxSum(vector<int> &arr, int k)
{
    int n = arr.size();

    int ans = 0;

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (k == 1)
    {
        ans = (kadanesForOne(arr, n)) % N;
    }
    else if (sum > 0)
    {
        ans = (kadanesForTwo(arr, n) + ((k - 2) * (sum))) % N;
    }
    else
    {
        ans = (kadanesForTwo(arr, n)) % N;
    }
    if (ans < 0)
        return 0;
    return ans % N;
}
int kadanesForOne(vector<int> arr, int n)
{
    int finalans = arr[0];
    int curr = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr = max(arr[i], arr[i] + curr);
        finalans = max(finalans, curr);
    }
    return finalans;
}
int kadanesForTwo(vector<int> arr, int n)
{
    int finalans = arr[0];
    int curr = arr[0];
    for (int i = 1; i < 2 * n; i++)
    {
        curr = max(arr[i % n], arr[i % n] + curr);
        finalans = max(finalans, curr);
    }
    return finalans;
}

int main()
{

    return 0;
}