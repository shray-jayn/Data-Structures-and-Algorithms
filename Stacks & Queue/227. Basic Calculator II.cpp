#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// T.C. -> O(n)    S.C. => O(n)
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int calculate(string s)
{

    int num = 0;
    char prevSign = '+';

    stack<int> stk;

    for (int i = 0; i < s.length(); i++)
    {

        if (isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }

        if (isOperator(s[i]) || i == s.length() - 1)
        {

            if (prevSign == '+')
            {
                stk.push(num);
            }

            else if (prevSign == '-')
            {
                stk.push(-num);
            }

            else if (prevSign == '*')
            {
                int top = stk.top();
                stk.pop();
                stk.push(top * num);
            }

            else if (prevSign == '/')
            {
                int top = stk.top();
                stk.pop();
                stk.push(top / num);
            }

            num = 0;
            prevSign = s[i];
        }
    }

    int res = 0;

    while (!stk.empty())
    {
        res += stk.top();
        stk.pop();
    }

    return res;
}

int main()
{
    string s;
    cin >> s;

    cout << calculate(s) << endl;

    return 0;
}