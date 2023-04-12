#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int longestSubarray(vector<int> &nums)
{
    int n = nums.size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            count++;
        }
    }

    if (count == 0)
    {
        return n - 1;
    }
    else if (count == n)
    {
        return 0;
    }

    int i = 0, j = 0;
    int one_count = 0, zero_count = 0;
    int len = 0, ans = 0;

    while (j < n)
    {
        if (nums[j] == 0)
        {
            zero_count++;
        }
        else
        {
            one_count++;
        }

        if (zero_count <= 1)
        {
            if (zero_count == 0)
            {
                len = j - i + 1;
            }
            else
            {
                len = j - i;
            }

            ans = max(ans, len);
            j++;
        }
        else if (zero_count > 1)
        {
            while (zero_count > 1)
            {
                if (nums[i] == 0)
                {
                    zero_count--;
                }
                else
                {
                    one_count--;
                }

                i++;
            }
            if (zero_count == 0)
            {
                len = j - i + 1;
            }
            else
            {
                len = j - i;
            }

            ans = max(ans, len);
            j++;
        }
    }

    return ans;
}

int main()
{

    return 0;
}