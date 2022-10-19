#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Pair
{
    stack<int> st;
    char sign;

    Pair(stack<int> st, char ch)
    {
        this->sign = ch;
        this->st = st;
    }
};

void cal(stack<int> st, int val, char sign)
{
    if (sign == '+')
    {
        st.push(val);
    }
    if (sign == '-')
    {
        st.push(-val);
    }
    if (sign == '*')
    {
        int a = st.top();
        st.pop();
        st.push(a * val);
    }
    if (sign == '/')
    {
        int a = st.top();
        st.pop();
        st.push(a / val);
    }
}

int calculate(string s)
{
    int n = s.size();

    stack<int> st;
    stack<Pair> stParentheses;

    char sign = '+';

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (isdigit(s[i])) // it is a digit
        {
            int val = 0;

            while (i < s.size() and isdigit(s[i]))
            {
                val = val * 10 + s[i] - '0';
                i++;
            }
            i--;

            cal(st, val, sign);
        }

        else if (ch == '(')
        {
            stParentheses.push({st, sign});
            sign = '+';
            st.empty();
        }

        else if (ch == ')')
        {
            int val = 0;

            while (st.size() > 0)
            {
                val += st.top();
                st.pop();
            }

            Pair p = stParentheses.top();
            stParentheses.pop();

            st = p.st;
            sign = p.sign;

            cal(st, val, sign);
        }

        

        else if (ch != ' ')
        {
            sign = ch;
        }
    }
}

int main()
{

    return 0;
}