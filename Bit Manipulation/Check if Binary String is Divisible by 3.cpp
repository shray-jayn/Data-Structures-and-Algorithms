#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isDivisibleBy3(string s)
{
    int n = s.size();

    int odd = 0;
    int even = 0;

    for (int i = 0; i < n; i++)
    {
        int bit = s[i] - '0';

        if (i % 2 == 0)
        {
            even += bit;
        }
        else
        {
            odd += bit;
        }
    }

    int delta = even - odd;

    if (delta % 11 == 0)
    {
        return true;
    }

    return false;
}

int main()
{

    return 0;
}