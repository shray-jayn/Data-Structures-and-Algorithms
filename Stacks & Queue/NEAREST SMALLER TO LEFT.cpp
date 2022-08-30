#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> nextLargerElement(vector<ll> arr, int n)
{
    vector<ll> ans;

    int n = arr.size() - 1;

    stack<ll> st;

    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            ans.push_back(-1);
        }

        if (st.size() > 0 and st.top() < arr[i])
        {
            ans.push_back(st.top());
        }

        else if (st.size() > 0 and st.top() >= arr[i])
        {
            while (st.size() > 0 and st.top() >= arr[i])
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

    return ans;
}

int main()
{

    return 0;
}