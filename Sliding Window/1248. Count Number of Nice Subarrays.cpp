#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int numberOfSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0, j = 0;
    int count = 0, ans = 0;

    while (j < n)
    {
        if (nums[j] % 2 == 1)
        {
            count++;
        }
        else
        {
            ans += ans;
        }

        if (count < k)
        {
            j++;
        }
        else if (count == k)
        {
            ans++;

            while (count == k)
            {
                if (nums[i] % 2 == 1)
                {
                    count--;
                }
                else
                {
                    ans++;
                }
                i++;
            }
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k = 2;

    cout << numberOfSubarrays(nums, k) << endl;

    return 0;
}