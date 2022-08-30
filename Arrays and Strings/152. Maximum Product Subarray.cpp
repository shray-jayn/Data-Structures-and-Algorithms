#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxProduct(vector<int> &nums)
{
    int n = nums.size();

    int ans = INT_MIN;
    int currProduct = 1;

    for (int i = 0; i < n; i++)
    {
        currProduct *= nums[i];
        ans = max(ans, currProduct);

        if (currProduct == 0)
        {
            currProduct = 1;
        }   
    }

    currProduct = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        currProduct *= nums[i];
        ans = max(ans, currProduct);

        if (currProduct == 0)
        {
            currProduct = 1;
        }
    }

    return ans;
}

int main()
{

    return 0;
}