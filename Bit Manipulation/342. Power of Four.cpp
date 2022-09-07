#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isPowerOfFour(int n)
{
    int fac = 0b01010101010101010101010101010101;

    if (n > 0)
    {
        if ((n & (n - 1)) == 0)
        {
            if ((fac & n) > 0)
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