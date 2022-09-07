#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isPowerOfTwo(int n)
{

    if (n == 0 or n == -2147483648) // edge cases
    {
        return 0;
    }

    int val = (n & (n - 1));

    if (val == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int main()
{

    return 0;
}