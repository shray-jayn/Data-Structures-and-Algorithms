#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int divide(int dividend, int divisor)
{
    if (dividend == divisor)
    {
        return 1;
    }

    bool isPositive = (dividend < 0 == divisor < 0); // if both are of same sign, answer is positive

    dividend = abs(dividend);
    divisor = abs(divisor);

    int ans = 0;

    while (dividend >= divisor) // while dividend is greater than or equal to divisor
    {
        int q = 0;

        while (dividend > (divisor << (q + 1)))
        {
            q++;
        }

        ans += (1 << q);                      // add the power of 2 found to the answer
        dividend = dividend - (divisor << q); // reduce the dividend by divisor * power of 2 found
    }

    if (ans == (1 << 31) and isPositive) // if ans cannot be stored in signed int
        return INT_MAX;

    return isPositive ? ans : -ans;
}

int main()
{

    return 0;
}