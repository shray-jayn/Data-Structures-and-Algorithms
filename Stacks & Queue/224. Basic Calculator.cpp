#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int calculate(string s)
{
    int n = s.size();

    int sum = 0;
    int sign = +1;

    stack<pair<int, int>> st; // <prevRes , sign>

    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i])) // it is a digit
        {
            int num = 0;

            while (i < s.size() and isdigit(s[i]))
            {
                num = num * 10 + s[i] - '0';
                i++;
            }
            i--;

            sum += num * sign;

            sign = 1;
        }

        else if (s[i] == '(')
        {
            st.push({sum, sign});

            sum = 0;
            sign = 1;
        }

        else if (s[i] == ')')
        {
            auto temp = st.top();

            st.pop();

            sum = temp.first + temp.second * sum;
        }

        else if (s[i] == '-')
        {
            sign = -1 * sign;
        }
    }

    return sum;
}

int main()
{

    return 0;
}