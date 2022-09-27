#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int getRev(int n)
{
    int rev = 0;

    

    return rev;
}

int nthPalindromeBinary(int n)
{
    int count = 1;
    int length = 1;

    while (count < n)
    {
        length++;
        int elementsForThisLength = (1 << (length - 1) / 2);
        count += elementsForThisLength;
    }

    count -= (1 << (length - 1) / 2);

    int offSet = n - count - 1;

    int ans = (1 << (length - 1));
    ans = ans | (offSet << (length / 2));

    int valForReverse = (ans >> (length / 2));
    int rev = getRev(valForReverse);

    ans = ans | rev;

    return ans;
}

int main()
{

    return 0;
}