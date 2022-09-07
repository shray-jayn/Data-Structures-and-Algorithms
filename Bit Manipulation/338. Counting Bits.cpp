#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int largestPowerOf2InRange(int n)
{
    int x = 0;

    while ((1 << x) <= n)
    {
        x++;
    }

    return x - 1;
}

int countBits(int n)
{

    if (n == 0)
    {
        return 0;
    }
    int x = largestPowerOf2InRange(n);

    int bitsUpto2PowX = x * (1 << (x - 1));
    int msbFrom2PowXToN = n - (1 << x) + 1;

    int rest = n - (1 << x);

    int ans = bitsUpto2PowX + msbFrom2PowXToN + countBits(rest);

    return ans;
}

int main()
{

    return 0;
}