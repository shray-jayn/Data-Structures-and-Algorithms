#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool find132pattern(vector<int> &nums)
{

    stack<int> st;

    int thirdElement = INT_MIN; // nums[k]

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] < thirdElement)
            return true;
        while (!st.empty() && st.top() < nums[i])
        {
            thirdElement = st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return false;
}

int main()
{
    vector<int> nums = {-2, 1, 2, -2, 1, 2};

    cout << find132pattern(nums) << endl;

    return 0;
}