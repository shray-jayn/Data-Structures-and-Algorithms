#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> mostCompetitive(vector<int> &nums, int k)
{
    int n = nums.size();

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        int val = nums[i];

        while ((st.size() > 0) and (nums[i] < st.top()) and (n - i - 1 >= k - st.size()))
        {
            st.pop();
        }

        if (st.size() < k)
        {
            st.push(val);
        }
    }

    vector<int> ans(k);
    int i = k - 1;

    while (i >= 0)
    {
        ans[i] = st.top();
        st.pop();
        i--;
    }

    return ans;
}

int main()
{

    return 0;
}