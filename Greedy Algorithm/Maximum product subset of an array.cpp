#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long int findMaxProduct(vector<int> &a, int n)
{
    if (n == 1)
    {
        return a[0];
    }

    long long int product = 1, mod = 1e9 + 7;

    int zero = 0, negative = 0;
    int maxNegative = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            zero++;
            continue;
        }

        else if (a[i] < 0)
        {
            negative++;
            maxNegative = max(maxNegative, a[i]);
        }

        product = (product * a[i]) % mod;
    }

    if (zero == n)
    {
        return (0);
    }
    if (negative == 1 && zero + negative == n)
    {
        return (0);
    }
    if (negative & 1) // odd number of negative elements
    {
        product /= maxNegative;
    }

    return (product);
}
int main()
{

    return 0;
}