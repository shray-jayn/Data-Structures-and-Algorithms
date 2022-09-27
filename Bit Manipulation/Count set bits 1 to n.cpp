#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int largestPowerOf2inRange(int n)
{
    int x = 0;

    while ((1 << x) <= n)
    {
        x++;
    }

    return x - 1;
}

int countTotalSet(int n)
{

    if (n == 0)
    {
        return 0;
    }

    int x = largestPowerOf2inRange(n);

    int bitsUpto2PowX = x * ((1 << (x - 1))); //  (2^(x-1))* X

    int msbFrom2PoxToN = n - ((1 << x)) + 1; // N - 2^x+1;

    int rest = countTotalSet(n - 1);

    int ans = bitsUpto2PowX + msbFrom2PoxToN + rest;

    return ans;
}

int main()
{

    return 0;
}