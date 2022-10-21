#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &num)
    {
        int start = 0, end = num.size() - 1;

        while (start < end)
        {
            if (num[start] < num[end])
                return num[start];

            int mid = (start + end) / 2;

            if (num[mid] > num[start] or num[mid] > num[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }

        return num[start];
    }
};