#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void wiggleSort(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n-1; i++)
    {
        // EVEN INDEX

        if (nums[i] > nums[i + 1] and i % 2 == 0)
        {
            swap(nums[i], nums[i + 1]);
        }

        // ODD INDEX

        if (nums[i] < nums[i + 1] and i % 2 == 1)
        {
            swap(nums[i], nums[i + 1]);
        }
    }
}

int main()
{

    return 0;
}