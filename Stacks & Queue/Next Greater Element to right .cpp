#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> nextLargerElement(vector<ll> arr, int n)
{
    vector<ll> ans;
    stack<ll> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            ans.push_back(-1);
        }

        if (st.size() > 0 and st.top() > arr[i])
        {
            ans.push_back(st.top());
        }

        else if (st.size() > 0 and st.top() <= arr[i])
        {
            while (st.size() > 0 and st.top() <= arr[i])
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

        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<ll> i = {-2, 1, 2, -2, 1, 2};
    vector<ll> result = nextLargerElement(i, 6);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}