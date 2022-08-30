#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int scoreOfParentheses(string s)
{
    int n = s.size();

    stack<int> st;

    // ( => -1

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(-1);
        }

        else
        {
            if (st.top() == -1)
            {
                st.pop();
                st.push(1);
            }

            else
            {
                int val = 0;

                while (st.top() != -1)
                {
                    val += st.top();
                    st.pop();
                }

                st.pop(); // remove last opening bracket

                st.push(2 * val);
            }
        }
    }

    int val = 0;

    while (st.size() > 0)
    {
        val += st.top();
        st.pop();
    }

    return val ;
}

int main()
{

    return 0;
}