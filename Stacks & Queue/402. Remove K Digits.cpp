#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string removeKdigits(string num, int k)
{
    int n = num.size();

    string res = "";

    stack<char> st;

    for (int i = 0; i < n; i++)
    {

        if (st.size() == 0)
        {
            st.push(num[i]);
        }

        else if (st.size() > 0 and num[i] < st.top() and k > 0)
        {
            while (st.size() > 0 and num[i] < st.top() and k > 0)
            {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }
        else
        {
            st.push(num[i]);
        }

        if (st.size() == 1 and num[i] == '0')
        {
            st.pop();
        }
    }
    while (k && !st.empty())
    {
        --k;
        st.pop();
    }

    while (!st.empty())
    {
        res.push_back(st.top()); // pushing stack top to string
        st.pop();                // pop the top element
    }

    reverse(res.begin(), res.end()); // reverse the string

    if (res.length() == 0)
        return "0";

    return res;
}

int main()
{

    return 0;
}