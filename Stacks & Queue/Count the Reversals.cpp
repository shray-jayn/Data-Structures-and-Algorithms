#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countRev(string s)
{
    int n = s.size();

    if (n % 2)
        return -1;

    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if (st.size() != 0 and s[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        else
        {
            st.push(s[i]);
        }
    }
    int leftString = st.size();

    int openingBr = 0, closingBr = 0;

    while (st.size() and st.top() == '{')
    {
        st.pop();
        openingBr++;
    }

    return leftString / 2 + openingBr % 2;
}

int main()
{

    return 0;
}