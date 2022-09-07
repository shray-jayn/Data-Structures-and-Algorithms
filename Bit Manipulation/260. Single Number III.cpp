#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int XOR = 0;

    for (int i = 0; i < n; i++)
    {
        XOR = nums[i] ^ XOR;
    }

    cout << XOR << endl;

    int rsbm = XOR & -XOR;

    cout << rsbm << endl;
    
    int x = 0;
    int y = 0;

    for (int i = 0; i < n; i++)
    {
        int val = nums[i];

        if ((val & rsbm == 0))
        {
            x = x ^ val;

            cout << "x- " << x << endl;
        }
        else
        {
            y = y ^ val;
            cout << "y- " << y << endl;
        }
    }

    if (x > y)
    {
        return {y, x};
    }

    return {x, y};
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    // vector<int> nums = {1,0};

    vector<int> ans = singleNumber(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}