#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int longestSubarray(vector<int> &nums, int limit)
{
    int n = nums.size();

    int i = 0;
    int j = 0;

    int maxLen = 0;

    deque<int> maxEle;
    deque<int> minEle;

    while (j < n)
    {
        while (maxEle.size() > 0 and maxEle.back() < nums[j])
        {
            maxEle.pop_back();
        }

        maxEle.push_back(nums[j]);

        while (minEle.size() > 0 and minEle.back() > nums[j])
        {
            minEle.pop_back();
        }

        minEle.push_back(nums[j]);

        int diff = maxEle.front() - minEle.front();

        if (diff <= limit)
        {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        else if (diff > limit)
        {
            while (diff > limit)
            {
                if (maxEle.front() == nums[i])
                {
                    maxEle.pop_front();
                }
                if (minEle.front() == nums[i])
                {
                    minEle.pop_front();
                }

                i++;

                diff = maxEle.front() - minEle.front();
            }

            j++;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> nums = {10, 1, 2, 4, 7, 2};
    int limit = 5;

    cout << longestSubarray(nums, limit) << endl;

    return 0;
}