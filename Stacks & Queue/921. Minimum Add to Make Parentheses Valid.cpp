#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minAddToMakeValid(string s)
{
    int n = s.size();

    stack<char> st;

    for (int i = 0; i < n; i++) // Process the string
    {
        char ch = s[i];

        if (ch == '(')
        {
            st.push(ch);
        }
        else
        {
            if (st.size() > 0 and st.top() == '(') // check if top element exist and is it '('
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }

    return st.size();
}
