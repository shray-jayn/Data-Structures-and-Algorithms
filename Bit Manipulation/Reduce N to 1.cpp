#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minimumSteps(int n)
{
    int res = 0;

    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else if (n == 3)
        {
            n = n - 1;
        }
        else if (n % 4 == 1)
        {
            n = n - 1;
        }
        else if (n % 4 == 3)
        {
            n + 1;
        }

        res++;
    }

    return res;
}

int main()
{

    return 0;
}