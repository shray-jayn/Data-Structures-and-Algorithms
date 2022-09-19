#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

double findMaxAverage(vector<int> &nums, int k)
{
    double sum = 0, res = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i < k)
            sum += nums[i];
        else
        {
            res = max(sum, res);
            sum += nums[i] - nums[i - k];
        }
    }
    res = max(sum, res);
    return res / k;
}

int main()
{

    return 0;
}