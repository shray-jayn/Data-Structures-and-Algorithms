#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();

    vector<int> suffixProduct(n);
    vector<int> prefixProduct(n);

    suffixProduct[0] = 1;
    prefixProduct[n - 1] = 1;

    for (int i = 1; i < n; i++)
    {
        suffixProduct[i] = suffixProduct[i - 1] * (nums[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        prefixProduct[i] = prefixProduct[i + 1] * (nums[i + 1]);
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = prefixProduct[i] * suffixProduct[i];
    }

    return nums;
}
// TC: O(n)
// SC: O(n)

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans(size(nums), 1);
    for (int i = 1; i < size(nums); i++) // store prefix product
        ans[i] = ans[i - 1] * nums[i - 1];
    for (int i = size(nums) - 1, suffixProd = 1; i >= 0; i--)
    {
        ans[i] *= suffixProd;  // multiply stored prefix product with suffix product
        suffixProd *= nums[i]; // update suffix product
    }
    return ans;
}
// TC: O(n)
// SC: O(1)

int main()
{

    return 0;
}