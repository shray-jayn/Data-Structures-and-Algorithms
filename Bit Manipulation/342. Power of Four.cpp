#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isPowerOfFour(int n) // must be even power of 2
{
    int fac = 0b01010101010101010101010101010101;

    if (n > 0)
    {
        if ((n & (n - 1)) == 0)
        {
            if ((fac & n) > 0) // if(fac & n == 0 ) => number is odd power of 2 => false
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    return 0;
}