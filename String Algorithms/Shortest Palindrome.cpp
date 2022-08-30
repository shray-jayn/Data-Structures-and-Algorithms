#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solution(string txt, string pat)
{
    string temp = pat + '#' + txt;

    vector<int> z = zFunction(temp);

    for (int i = 1; i < temp.size(); i++)
    {
        if (z[i] == pat.size())
        {
            cout << i - pat.size() - 1 << endl;
        }
    }

    return;  
}

vector<int> zFunction(string st)
{
    int n = st.size();

    vector<int> z(n, 0);

    int l = 0, r = 0;

    for (int i = 0; i < n; i++)
    {
        if (i <= r)
        {
            z[i] = min(r - l + 1, z[i - l]);
        }

        while (i + z[i] < n and st[z[i]] == st[i + z[i]])
        {
            z[i]++;
        }

        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}
