#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int powerOfTwo(int n)
{
    int i = 1;

    while (i * 2 <= n)
    {
        i = i * 2;
    }

    return i;
}

int josephus(int n)
{
    int highestPower2 = powerOfTwo(n);

    int l = n - highestPower2;

    return 2 * l + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}