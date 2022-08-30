#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> nextLargerElement(int arr[], int n)
{
    vector<int> ans;

    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            ans.push_back(-1);
        }

        if (st.size() > 0 and st.top().first > arr[i])
        {
            ans.push_back(st.top().second);
        }

        else if (st.size() > 0 and st.top().first <= arr[i])
        {
            while (st.size() > 0 and st.top().first <= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }

        st.push({arr[i], i});
    }

    return ans;
}

vector<int> calculateSpan(int price[], int n)
{
    // Your code here

    vector<int> ans = nextLargerElement(price, n);

    for (int i = 0; i < n; i++)
    {
        ans[i] = i - ans[i];
    }
    return ans;
}

int main()
{

    return 0;
}