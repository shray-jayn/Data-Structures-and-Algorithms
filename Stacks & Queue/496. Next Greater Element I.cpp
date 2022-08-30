#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> nextGreaterToRight(vector<int> &nums)
{
    int n = nums.size() - 1;

    vector<int> ans;

    stack<int> st;

    for (int i = n; i >= 0; i--)
    {
        // case1 : Empty stack

        if (st.size() == 0)
        {
            ans.push_back(-1);
        }

        // Case2 : Element greater than curr

        else if (st.size() > 0 and st.top() > nums[i])
        {
            ans.push_back(st.top());
        }

        // Case3 : Element smaller than curr

        else if (st.size() > 0 and st.top() <= nums[i])
        {
            while (st.size() > 0 and st.top() <= nums[i])
            {
                st.pop();
            }

            if (st.size() == 0)
            {
                ans.push_back(-1);
            }

            else
            {
                ans.push_back(st.top());
            }
        }

        st.push(nums[i]);
    }

    reverse(ans.begin(), ans.end());

    return ans;
    
}

int main()
{
    return 0;
}
