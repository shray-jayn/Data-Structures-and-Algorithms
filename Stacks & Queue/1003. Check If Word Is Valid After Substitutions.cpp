#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isValid(stack<char> &st)
{
    if (st.size() < 2)
    {
        return false;
    }
    char b = st.top();
    st.pop();
    char a = st.top();

    if (a == 'a' and b == 'b')
    {
        return true;
    }

    return false;
}
bool isValid(string s)
{
    int n = s.size();

    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (ch == 'c')
        {
            if (isValid(st)) // paired
            {
            }

            else
            {
                return false;
            }
        }
        else
        {
            st.push(s[i]);
        }
    }

    return st.empty() == true;
}

int main()
{

    return 0;
}