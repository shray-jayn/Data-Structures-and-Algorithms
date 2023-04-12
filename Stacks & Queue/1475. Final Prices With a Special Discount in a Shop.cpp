#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Next smaller element in right

vector<int> finalPrices(vector<int> &prices)
{
    int n = prices.size();

    stack<int> st;
    vector<int> res;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            res.push_back(prices[i]);
        }
        if (st.size() > 0 and st.top() <= prices[i])
        {
            res.push_back(prices[i] - st.top());
        }
        else if (st.size() > 0 and st.top() > prices[i])
        {
            while (st.size() > 0 and st.top() > prices[i])
            {
                st.pop();
            }

            if (st.size() == 0)
            {
                res.push_back(prices[i]);
            }
            else
            {
                res.push_back(prices[i] - st.top());
            }
        }

        st.push(prices[i]);
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{

    return 0;
}