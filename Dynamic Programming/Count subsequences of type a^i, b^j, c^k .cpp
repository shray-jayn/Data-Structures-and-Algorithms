#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int fun(string &s)
{
    int n = s.size();

    int a = 0;
    int ab = 0;
    int abc = 0;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (ch == 'a')
        {
            a = 2 * a + 1;
        }

        else if (ch == 'b')
        {
            ab = 2 * ab + a;
        }

        else if (ch == 'c')
        {
            abc = 2 * abc + ab;
        }
    }

    return abc;
}

int main()
{

    return 0;
}