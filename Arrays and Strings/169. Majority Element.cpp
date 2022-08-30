#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int majorityElement(vector<int> &nums)
{
    int n = nums.size();

    int count = 1;
    int maxEle = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] != maxEle)
        {
            count--;
        }

        else if (maxEle == nums[i])
        {
            count++;
        }

        if (count == 0)
        {
            maxEle = nums[i];
            count = 1;
        }
    }

    return maxEle;
}

int main()
{

    return 0;
}