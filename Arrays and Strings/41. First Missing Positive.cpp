#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int firstMissingPositive(vector<int> &nums)
{
    // Srep 1 : Mark the elements which are out of range to 1  and check presence of 1 ;

    int n = nums.size();

    bool one = 0;

    for(int i = 0 ;i<n ;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            one = 1;
        }

        if (nums[i] > n or nums[i] < 1)
        {
            nums[i] = 1;
        }
    }


     for(int i = 0 ;i<n ;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    if (one == false)
    {
        return 1;
    }

    // Step 2 : Map the elements with indexes

    for (int i = 0; i < n; i++)
    {
        int idx = abs(nums[i]);

        nums[idx - 1] = -abs(nums[idx - 1]);

        cout << idx << " -> " << nums[idx - 1] << endl;
    }

    // Srep 3 : Find out the missing Interger


     for(int i = 0 ;i<n ;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            return i + 1;
        }
    }

    return n + 1;
}

int main()
{
    vector<int> c = {3, 4, -1, 1};

    int a = firstMissingPositive(c);

    cout << a << endl;

    return 0;
}