#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    int j = 0;

    while (j < n)
    {
        if (nums[j] == 0)
        {
            j++;
        }
        else
        {
            swap(nums[i], nums[j]);
            j++;
            i++;
        }
    }
    return;
}

int main()
{

    return 0;
}