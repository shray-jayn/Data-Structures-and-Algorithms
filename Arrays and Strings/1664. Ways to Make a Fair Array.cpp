#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int waysToMakeFair(vector<int> &nums)
{
    int n = nums.size();
    vector<int> odd(n, 0), even(n, 0); // PerfixSum array for even and odd elements
    int oddS = 0, evenS = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        // making the PerfixSum arrays
        if (i % 2)
        {
            oddS += nums[i];
        }
        else
        {
            evenS += nums[i];
        }
        odd[i] = oddS;
        even[i] = evenS;
    }

    // for 0 index :
    oddS = even[n - 1] - even[0];
    evenS = odd[n - 1];
    if (oddS == evenS)
    {
        ans++;
    }

    for (int i = 1; i < n; i++)
    {
        oddS = odd[i - 1] + even[n - 1] - even[i];
        evenS = even[i - 1] + odd[n - 1] - odd[i];
        if (oddS == evenS)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}