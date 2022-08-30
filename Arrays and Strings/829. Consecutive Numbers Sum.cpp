#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int consecutiveNumbersSum(int n)
{
    int count = 0;

    for (int k = 1; 2 * n > k * (k - 1); k++)
    {
        int numerator = n - (k * (k - 1)) / 2;

        if (numerator % k == 0)
        {
            count++;
        }
    }

    return count;
}

int main()
{

    return 0;
}