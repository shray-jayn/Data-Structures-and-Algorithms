#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            nums[i] = nums[i] * (-1);
        }
    }

    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        if (nums[start] >= nums[end])
        {
            result.push_back(nums[start]);
            start++;
        }

        else if (nums[start] < nums[end])
        {
            result.push_back(nums[end]);
            end--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int val = result[i];
        result[i] = val * val;
    }
    
    reverse(result.begin(), result.end());

    return result;
}

int main()
{

    return 0;
}