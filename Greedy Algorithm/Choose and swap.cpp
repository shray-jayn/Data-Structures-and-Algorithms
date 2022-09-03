#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string chooseAndSwap(string a)
{
    set<char> st;

    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }

    for (int i = 0; i < a.size(); i++)
    {
        st.erase(a[i]);

        if (st.empty()) // when all element are visited
        {
            break;
        }

        char ch = *st.begin(); // top element of set ;

        if (ch < a[i])
        {
            int ch1 = a[i];

            for (int j = 0; j < a.size(); j++)
            {
                if (a[j] == ch)
                {
                    a[j] = ch1;
                }

                else if (a[j] == ch1)
                {
                    a[j] = ch;
                }
            }

            break;
        }
    }

    return a;
}

int main()
{

    return 0;
}