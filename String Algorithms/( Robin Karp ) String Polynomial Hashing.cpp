#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long hashcode(string s)
{
    long p = 31;
    long pow = 31;
    long ans = s[0] - 'a' + 1;
    long mod = 1000000007;

    for (int i = 1; i < s.length(); i++)
    {
        ans += (s[i] - 'a' + 1) * pow % mod;

        pow = (pow * p) % mod;
    }

    return ans;
}

int main()
{

    return 0;
}