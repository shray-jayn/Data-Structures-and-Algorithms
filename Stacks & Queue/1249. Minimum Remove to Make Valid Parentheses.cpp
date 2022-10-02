#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string minRemoveToMakeValid(string s)
{
    int n = s.size();

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            if (st.size() > 0 and s[st.top()] == '(')
            {
                st.pop();
            }
            else
            {
                s[i] = '.';
            }
        }
    }

    while (st.size() > 0)
    {
        int i = st.top();
        st.pop();

        s[i] = '.';
    }

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (s[i] != '.')
        {
            ans.push_back(s[i]);
        }
    }

    return ans;
}

