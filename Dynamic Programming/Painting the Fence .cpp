#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long countWays(int n, int k)
{

    if (n == 1)
        return k;
    if (n == 0)
        return 0;
    if (k == 0)
        return 0;


    ll same = k;
    ll differient = k * (k - 1);
    ll total = same + differient;

    for (int i = 3; i < n + 1; i++)
    {
        same = differient * 1;

        differient = total * (k - 1);

        total = same + differient;
    }

    return total%1000000007;
}

int main()
{

    return 0;
}